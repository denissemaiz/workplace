#include "FUNCIONES_USER.h"
#include "FUNCIONES_RESERVAS.h"
#include "../MENUS/MENUS.h"
#include "ReservaDTO.h"
#include "ReservasDAL.h"
#include "EmpleadoDAL.h"

bool validarDni(int dni)
{
    int cifras=0;

    while(dni > 0)
    {
        dni = dni / 10;
        cifras++;
    }

    if(cifras==8)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int listarReservasFuturas(int dni)
{
    ReservasDAL regReserva;
    EmpleadoDAL regEmpleado;

    int legajo, contador=0;
    Fecha fechaHoy;

    /*fechaHoy.Mostrar();
    getch();

    fechaHoy.operator++();
    fechaHoy.operator++();

    fechaHoy.Mostrar();
    getch();*/

    int cantidad=regReserva.getCantidad();
    ReservaDTO* vecReserva= new ReservaDTO[cantidad];

    if (cantidad > 0)
    {
        legajo = regEmpleado.buscarLegajo(dni);
        regReserva.leerTodos(vecReserva, cantidad);
        for(int i=0; i<cantidad; i++)
        {
            if(vecReserva[i].getLegajo()==legajo
                    && vecReserva[i].getEstado()==true
                    && vecReserva[i].getFecha().operator>=(fechaHoy))
            {
                contador++;
                system("cls");
                rectangulo (2, 2, 100, 20);
                mostrar_mensaje ("***   ANULANDO RESERVAS   ***", 39, 4);
                mostrar_mensaje ("     --------------------  ", 39, 5);
                mostrar_mensaje ("ESTAS SON TUS RESERVAS: ", 20, 9);
                vecReserva[i].mostrar();
                rlutil::  locate (54,21);
                cout<<contador;
                rlutil::  locate (61,21);
                system("pause");
            }
        }
    }
    return contador;
}

int listarHistorialReservas(int dni)
{
    ReservasDAL regReserva;
    EmpleadoDAL regEmpleado;

    int legajo, contador=0;
    Fecha fechaHoy;

    int cantidad=regReserva.getCantidad();
    ReservaDTO* vecReserva= new ReservaDTO[cantidad];

    if (cantidad > 0)
    {
        legajo = regEmpleado.buscarLegajo(dni);
        regReserva.leerTodos(vecReserva, cantidad);
        for(int i=0; i<cantidad; i++)
        {
            if(vecReserva[i].getLegajo()==legajo)
            {
                contador++;
                system("cls");
                rectangulo (2, 2, 100, 20);
                mostrar_mensaje ("***   HISTORIAL DE RESERVAS   ***", 39, 4);
                mostrar_mensaje ("      ---------------------  ", 39, 5);
                mostrar_mensaje ("ESTAS SON TUS RESERVAS: ", 20, 9);
                vecReserva[i].mostrar();
                rlutil::  locate (54,21);
                cout<<contador;
                rlutil::  locate (61,21);
                system("pause");
            }
        }
    }
    return contador;
}

bool chequearEmpleado(int dni)
{
    EmpleadoDAL regEmpleado;
    EmpleadoDTO objEmpleado;

    int nroEmpleado;
    bool existe = false;

    nroEmpleado = regEmpleado.buscar(dni);
    objEmpleado = regEmpleado.leer(nroEmpleado);

    if(nroEmpleado != -1
       && objEmpleado.getEstado() == true)
    {
        existe = true;
    }
    return existe;
}


void anularReserva(int dni)
{
    ReservasDAL regReserva;
    ReservaDTO objReserva;

    int cantReservas, nroReserva, nroRegReserva;
    cantReservas = listarReservasFuturas(dni);

    if(cantReservas == 0)
    {
        system("cls");
        rectangulo (2, 2, 100, 20);
        mostrar_mensaje ("***  NO HAY REGISTRO DE RESERVAS FUTURAS ***", 31, 11);
        system("pause>nul");
        system("cls");
        menuUser(dni);
    }

    nroReserva = ingresarNroReserva();

    while(!chequearNroReserva(nroReserva, dni))
    {
        system("cls");
        rectangulo (2, 2, 100, 20);
        mostrar_mensaje ("EL NRO DE RESERVA INGRESADO ES INVALIDO", 30, 12);
        mostrar_mensaje ("DESEA INGRESARLO DE NUEVO?", 35, 14);
        if(!seleccionarSiNo())
        {
            system("cls");
            salirSistemaUser();
            menuUser(dni);
        }
        else
        {
            nroReserva = ingresarNroReserva();
        }
    }

    nroRegReserva = regReserva.buscar(nroReserva);
    objReserva = regReserva.leer(nroRegReserva);
    objReserva.mostrar();

    mostrar_mensaje (" CONFIRMAS LA ANULACION: ", 40, 17);

    if(!seleccionarSiNo())
    {
        menuUser(dni);
        return;
    }
    else
    {
        objReserva.setEstado(false);
        regReserva.modificar(objReserva, nroRegReserva);
        system("cls");
        rectangulo (2, 2, 100, 20);
        mostrar_mensaje ("*** LA RESERVA FUE ANULADA ***", 35, 14);
        system("pause>nul");
        system("cls");
        menuUser(dni);
    }
}

int ingresarNroReserva()
{
    int nroReserva;
    system("cls");
    rectangulo (2, 2, 100, 20);
    mostrar_mensaje ("***   ANULANDO RESERVAS   ***", 38, 4);
    mostrar_mensaje ("     --------------------  ", 38, 5);
    mostrar_mensaje ("QUE NRO DE RESERVA DESEAS ANULAR? ", 20, 9);
    rectangulo (54, 8, 5, 1);
    rlutil::  locate (56,9);
    cin>>nroReserva;
    return nroReserva;
}
