#include "MENUS.h"
#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_USER.h"
#include "FUNCIONES_RESERVAS.h"
#include "ReservaDTO.h"
#include "ReservasDAL.h"
#include "EmpleadoDAL.h"
#include "EmpleadoDTO.h"

int ingresarNroReserva();

void anularReserva(int dni)
{
    ReservasDAL regReserva;
    ReservaDTO objReserva;

    int cantReservas, nroReserva, nroRegReserva;
    cantReservas = listarReservasFuturas(dni);

    if(cantReservas == 0)
    {
        system("cls");
        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("NO HAY REGISTRO DE RESERVAS FUTURAS", 20, 14);
        system("pause>nul");
        system("cls");
        menuUser(dni);
    }

    nroReserva = ingresarNroReserva();

    while(!chequearNroReserva(nroReserva, dni))
    {
        system("cls");
        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("EL NRO DE RESERVA INGRESADO ES INVALIDO", 30, 12);
        mostrar_mensaje ("DESEA INGRESARLO DE NUEVO?", 35, 14);
        if(!seleccionarSiNo())
        {
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
        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
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
    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 20);
    mostrar_mensaje ("***   ANULANDO RESERVAS   ***", 38, 4);
    mostrar_mensaje ("     --------------------  ", 38, 5);
    mostrar_mensaje ("QUE NRO DE RESERVA DESEAS ANULAR? ", 20, 9);
    rectangulo (54, 8, 5, 1);
    rlutil::  locate (56,9);
    cin>>nroReserva;
    return nroReserva;
}


