#include "../MENUS/MENUS.h"
#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_USER.h"
#include "FUNCIONES_RESERVAS.h"
#include "EspacioDeTrabajoDAL.h"
#include "EspacioDeTrabajoDTO.h"
#include "ReservasDAL.h"
#include "ReservaDTO.h"
#include "EmpleadoDAL.h"
#include "EmpleadoDTO.h"


int contarReservas(int espacio, Fecha fecha) ///cuenta reservas de X dia en Y espacio
{
    ReservasDAL regReserva;
    int cantReservas=0;

    int tamReservas=regReserva.getCantidad();
    ReservaDTO* vecReservas= new ReservaDTO[tamReservas];

    regReserva.leerTodos(vecReservas, tamReservas);

    for(int i=0; i<tamReservas; i++)
    {
        if(vecReservas[i].getEspacioTrabajo()==espacio
                && vecReservas[i].getFecha().operator==(fecha))
        {
            cantReservas++;
        }
    }

    return cantReservas;
}

int incrementarNroReserva()
{
    ReservasDAL regReserva;
    int ultReserva;

    ultReserva = regReserva.getCantidad();
    ultReserva++;

    return ultReserva;
}

void confirmacionReserva(int dni, int espacio, Fecha fecha)
{
    EmpleadoDTO objEmpleado;
    EmpleadoDAL regEmpleado;
    ReservaDTO objReserva;
    ReservasDAL regReserva;
    int nroEmpleado, nroReserva, legajo;
    bool disponibilidad=false;

    disponibilidad = consultarDisponibilidad(espacio, fecha);

    if(!disponibilidad)
    {
        menuFechaNoDisponible(dni, espacio);
    }
    if(!menuConfirmarReserva(espacio, fecha))
    {
        system("cls");
        menuUser(dni);
    }
    else
    {
        nroEmpleado = regEmpleado.buscar(dni);
        objEmpleado = regEmpleado.leer(nroEmpleado);
        legajo = objEmpleado.getLegajo();
        nroReserva = incrementarNroReserva();

        objReserva.setNumero(nroReserva);
        objReserva.setLegajo(legajo);
        objReserva.setEspacioTrabajo(espacio);
        objReserva.setFecha(fecha);
        objReserva.setEstado(true);

        /*objReserva.mostrar();
        getch();*/

        regReserva.agregar(objReserva);

        mostrar_mensaje ("*** SU RESERVA FUE REGISTRADA ***", 35, 20);
        getch();
        system("cls");

        system("cls");
        menuUser(dni);
    }
}

bool consultarDisponibilidad(int espacio, Fecha fecha)
{
    EspacioDeTrabajoDAL regEspacio;
    EspacioDeTrabajoDTO objEspacio;
    int nroRegEspacio, cantidadNoDisponible;
    bool disponible=false;

    cantidadNoDisponible = contarReservas(espacio, fecha);

    nroRegEspacio = regEspacio.buscar(espacio);
    objEspacio = regEspacio.leer(nroRegEspacio);

    if(objEspacio.getCantPuestos()>cantidadNoDisponible)
    {
        disponible = true;
    }
    return disponible;
}

bool chequearNroReserva(int nroReserva, int dni)
{
    ReservasDAL regReserva;
    ReservaDTO objReserva;
    EmpleadoDAL regEmpleado;
    EmpleadoDTO objEmpleado;

    int nroEmpleado, nroRegReserva, legajo;
    bool existe = false;

    nroEmpleado = regEmpleado.buscar(dni);
    objEmpleado = regEmpleado.leer(nroEmpleado);
    legajo = objEmpleado.getLegajo();
    nroRegReserva = regReserva.buscar(nroReserva);
    objReserva = regReserva.leer(nroRegReserva);

    if(nroRegReserva != -1
       && objReserva.getLegajo() == legajo
       && objReserva.getEstado() == true)
    {
        existe = true;
    }
    return existe;
}
