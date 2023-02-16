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

    int nroRegEmpleado, nroRegReserva, legajo;
    bool existe = false;

    nroRegEmpleado = regEmpleado.buscar(dni);
    objEmpleado = regEmpleado.leer(nroRegEmpleado);
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

int listarPorDni()
{
    EmpleadoDAL regEmpleado;
    EmpleadoDTO objEmpleado;
    ReservasDAL regReserva;

    int dni, nroRegEmpleado, legajo, hayRegistros = 0;

    mostrar_mensaje ("INGRESE EL DNI DEL EMPLEADO: ", 29, 8);
    mostrar_mensaje ("DNI: ", 29, 10);
    cin>>dni;

    int tamReservas=regReserva.getCantidad();
    ReservaDTO* vecReservas= new ReservaDTO[tamReservas];

    regReserva.leerTodos(vecReservas, tamReservas);

    nroRegEmpleado = regEmpleado.buscar(dni);
    if (nroRegEmpleado == -1)
    {
        return nroRegEmpleado;
    }
    objEmpleado = regEmpleado.leer(nroRegEmpleado);
    legajo = objEmpleado.getLegajo();

    for(int i=0; i<tamReservas; i++)
    {
        if(vecReservas[i].getLegajo()==legajo)
        {
            hayRegistros = 1;
            system("cls");
            rectangulo (2, 2, 100, 20);
            mostrar_mensaje ("DNI: ", 20, 10);
            cout<<dni;
            vecReservas[i].mostrar();
            rlutil::  locate (61,21);
            system("pause");
        }
    }
    return hayRegistros;
}

int listarPorLegajo()
{
    EmpleadoDAL regEmpleado;
    EmpleadoDTO objEmpleado;
    ReservasDAL regReserva;

    int nroRegEmpleado, legajo, hayRegistros = 0;

    mostrar_mensaje ("INGRESE EL LEGAJO DEL EMPLEADO: ", 29, 8);
    mostrar_mensaje ("LEGAJO: ", 29, 10);
    cin>>legajo;

    int tamReservas=regReserva.getCantidad();
    ReservaDTO* vecReservas= new ReservaDTO[tamReservas];

    regReserva.leerTodos(vecReservas, tamReservas);

    nroRegEmpleado = regEmpleado.buscarPorLegajo(legajo);
    if (nroRegEmpleado == -1)
    {
        return nroRegEmpleado;
    }

    for(int i=0; i<tamReservas; i++)
    {
        if(vecReservas[i].getLegajo()==legajo)
        {
            hayRegistros = 1;
            system("cls");
            rectangulo (2, 2, 100, 20);
            mostrar_mensaje ("LEGAJO: ", 20, 10);
            cout<<legajo;
            vecReservas[i].mostrar();
            rlutil::  locate (61,21);
            system("pause");
        }
    }
    return hayRegistros;
}

int listarPorEspacio()
{
    ReservasDAL regReserva;

    int espacio, hayRegistros = 0;

    mostrar_mensaje ("INGRESE EL ESPACIO DE TRABAJO: ", 29, 8);
    mostrar_mensaje ("TIPO DE ESPACIO: ", 29, 10);
    mostrar_mensaje ("1- DESK ", 37, 12);
    mostrar_mensaje ("2- SALA DE REUNIONES ", 37, 13);
    mostrar_mensaje ("3- ESTACIONAMIENTO ", 37, 14);
    mostrar_mensaje ("4- COMEDOR ", 37, 15);
    rlutil::  locate (46,10);
    cin>>espacio;

    if(espacio<1 || espacio>5)
    {
        hayRegistros = -1;
        return hayRegistros;
    }

    int tamReservas=regReserva.getCantidad();
    ReservaDTO* vecReservas= new ReservaDTO[tamReservas];

    regReserva.leerTodos(vecReservas, tamReservas);

    for(int i=0; i<tamReservas; i++)
    {
        if(vecReservas[i].getEspacioTrabajo()== espacio-1)
        {
            hayRegistros = 1;
            system("cls");
            rectangulo (2, 2, 100, 20);
            rlutil::  locate (20,8);
            cout<<"RESERVAS ";
            rlutil::  locate (30,8);
            switch(espacio-1)
            {
            case 0:
                cout<<"DESK";
                break;
            case 1:
                cout<<"SALA DE REUNIONES";
                break;
            case 2:
                cout<<"ESTACIONAMIENTO";
                break;
            case 3:
                cout<<"COMEDOR";
                break;
            }
            vecReservas[i].mostrar();
            rlutil:: locate (61,21);
            system("pause");
        }
    }
    return hayRegistros;
}

int totalReservasUltMes()
{
    ReservasDAL regReserva;
    Fecha fechaHoy;
    int mesPasado, contador = 0;

    mesPasado = fechaHoy.getMes()-1;

    int tamReservas=regReserva.getCantidad();
    ReservaDTO* vecReservas= new ReservaDTO[tamReservas];

    regReserva.leerTodos(vecReservas, tamReservas);

    for(int i=0; i<tamReservas; i++)
    {
        if(vecReservas[i].getFecha().getMes() == mesPasado)
        {
            contador++;
        }
    }
    return contador;
}

int totalReservasAnuladasUltMes()
{
    ReservasDAL regReserva;
    Fecha fechaHoy;
    int mesPasado, contador = 0;

    mesPasado = fechaHoy.getMes()-1;

    int tamReservas=regReserva.getCantidad();
    ReservaDTO* vecReservas= new ReservaDTO[tamReservas];

    regReserva.leerTodos(vecReservas, tamReservas);

    for(int i=0; i<tamReservas; i++)
    {
        if(vecReservas[i].getFecha().getMes() == mesPasado
                && vecReservas[i].getEstado()== false)
        {
            contador++;
        }
    }
    return contador;
}

float porcentajeReservasAnuladas()
{
    int totalRes=0, totalAnul=0;
    float porcentaje=0;

    totalAnul = totalReservasAnuladasUltMes();
    totalRes = totalReservasUltMes();

    if(totalRes != 0)
    {
        porcentaje = (((float)totalAnul)*100)/((float)totalRes);
    }

    return porcentaje;
}

int totalReservasAdmRRHH()
{
    ReservasDAL regReserva;
    Fecha fechaHoy;
    int mesPasado, contador = 0;

    mesPasado = fechaHoy.getMes()-1;  /**/

    int tamReservas=regReserva.getCantidad();
    ReservaDTO* vecReservas= new ReservaDTO[tamReservas];

    regReserva.leerTodos(vecReservas, tamReservas);

    for(int i=0; i<tamReservas; i++)
    {
        if(vecReservas[i].getFecha().getMes() == mesPasado
                && vecReservas[i].getEspacioTrabajo()== 0
                && vecReservas[i].getEstado()==true)
        {
            contador++;
        }
    }
    return contador;
}

int totalReservasMarkVentas()
{
    ReservasDAL regReserva;
    Fecha fechaHoy;
    int mesPasado, contador = 0;

    mesPasado = fechaHoy.getMes()-1;  /**/

    int tamReservas=regReserva.getCantidad();
    ReservaDTO* vecReservas= new ReservaDTO[tamReservas];

    regReserva.leerTodos(vecReservas, tamReservas);

    for(int i=0; i<tamReservas; i++)
    {
        if(vecReservas[i].getFecha().getMes() == mesPasado
                && vecReservas[i].getEspacioTrabajo()== 1
                && vecReservas[i].getEstado()==true)
        {
            contador++;
        }
    }
    return contador;
}

int totalReservasProdSist()
{
    ReservasDAL regReserva;
    Fecha fechaHoy;
    int mesPasado, contador = 0;

    mesPasado = fechaHoy.getMes()-1;

    int tamReservas=regReserva.getCantidad();
    ReservaDTO* vecReservas= new ReservaDTO[tamReservas];

    regReserva.leerTodos(vecReservas, tamReservas);

    for(int i=0; i<tamReservas; i++)
    {
        if(vecReservas[i].getFecha().getMes() == mesPasado
                && vecReservas[i].getEspacioTrabajo()== 2
                && vecReservas[i].getEstado()==true)
        {
            contador++;
        }
    }
    return contador;
}

int totalReservasContabFinanzas()
{
    ReservasDAL regReserva;
    Fecha fechaHoy;
    int mesPasado, contador = 0;

    mesPasado = fechaHoy.getMes()-1;

    int tamReservas=regReserva.getCantidad();
    ReservaDTO* vecReservas= new ReservaDTO[tamReservas];

    regReserva.leerTodos(vecReservas, tamReservas);

    for(int i=0; i<tamReservas; i++)
    {
        if(vecReservas[i].getFecha().getMes() == mesPasado
                && vecReservas[i].getEspacioTrabajo()== 3
                && vecReservas[i].getEstado()==true)
        {
            contador++;
        }
    }
    return contador;
}

int totalReservasGerenDirecc()
{
    ReservasDAL regReserva;
    Fecha fechaHoy;
    int mesPasado, contador = 0;

    mesPasado = fechaHoy.getMes()-1;

    int tamReservas=regReserva.getCantidad();
    ReservaDTO* vecReservas= new ReservaDTO[tamReservas];

    regReserva.leerTodos(vecReservas, tamReservas);

    for(int i=0; i<tamReservas; i++)
    {
        if(vecReservas[i].getFecha().getMes() == mesPasado
                && vecReservas[i].getEspacioTrabajo()== 3
                && vecReservas[i].getEstado()==true)
        {
            contador++;
        }
    }
    return contador;
}

