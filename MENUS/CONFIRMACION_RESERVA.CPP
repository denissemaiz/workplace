#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_USER.h"
#include "MENUS.h"
#include "EspacioDeTrabajoDAL.h"
#include "EspacioDeTrabajoDTO.h"
#include "ReservasDAL.h"
#include "ReservaDTO.h"
#include "EmpleadoDAL.h"
#include "EmpleadoDTO.h"

#include "Fecha.h"

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
        fechaNoDisponible(dni, espacio);
    }
    if(!reciboConfirmacionReserva(espacio, fecha))
    {
        SalirSistemaUser(); /**/// o vuelve a menuUser?
    }

    nroEmpleado = regEmpleado.buscar(dni);
    objEmpleado = regEmpleado.leer(nroEmpleado);
    legajo = objEmpleado.getLegajo();
    nroReserva = incrementarNroReserva();

    objReserva.setNumero(nroReserva);
    objReserva.setLegajo(legajo);
    objReserva.setEspacioTrabajo(espacio);
    objReserva.setFecha(fecha);
    objReserva.setEstado(true);

    regReserva.agregar(objReserva);
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


bool reciboConfirmacionReserva(int espacio, Fecha fecha)
{
    system("cls");
    rectangulo (2, 2, 100, 20);

    mostrar_mensaje ("USTED RESERVO:  ", 40, 4);
    mostrar_mensaje ("ESPACIO: ", 20, 7);
    switch(espacio)
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
    mostrar_mensaje ("DIA: ", 20, 9);
    fecha.Mostrar();
    mostrar_mensaje ("CONFIRMA LA RESERVA: ", 40, 18);

    int op=1, y=0;
    const char *opciones[] = {"SI","NO"};

    rlutil::hidecursor();

    do
    {
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],46,19,y==0);
        showItem (opciones[1],46,20,y==1);

        rlutil::locate(42,19+y);
        cout <<"==> " <<endl;

        switch(rlutil::getkey())
        {
        case 14: //UP
            rlutil::locate(42,19+y);
            cout <<"    " <<endl;
            y--;

            if (y<0)
            {
                y=0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(42,19+y);
            cout <<"    " <<endl;
            y++;

            if (y>1)
            {
                y=1;
            }
            break;

        case 1:         /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):
            switch(y)
            {
            case 0:     /// SI CONFIRMA
                return true;
                break;
            case 1:      /// NO CONFIRMA
                return false;
                break;
            }
        }
    }
    while(op!=0);
    system("pause>nul");
    return false;
}

void fechaNoDisponible(int dni, int espacio)
{
    system("cls");
    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::RED);
    mostrar_mensaje ("**   LO SENTIMOS NO HAY MAS DISPONIBILIDAD PARA LA FECHA SELECCIONADA  **  ", 19, 6);

    int op=1, y=0;;
    const char *opciones[] = {"VOLVER A CALENDARIO","VOLVER AL MENU PRINCIPAL"};

    rlutil::hidecursor();

    do
    {
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],35,10,y==0);
        showItem (opciones[1],35,11,y==1);

        rlutil::locate(31,10+y);
        cout <<"==> " <<endl;

        switch(rlutil::getkey())
        {
        case 14: //UP
            rlutil::locate(31,10+y);
            cout <<"    " <<endl;
            y--;

            if (y<0)
            {
                y=0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(31,10+y);
            cout <<"    " <<endl;
            y++;

            if (y>1)
            {
                y=1;
            }
            break;

        case 1:        /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1)

            switch(y)
            {
            case 0:     ///VOLVER A CALENDARIO
                cuadroSeleccionDia(dni, espacio);
                break;
            case 1:     ///MENU PRINCIPAL
                menuUser(dni);
                break;
            }
        }
    }
    while(op!=0);
    system("pause>nul");
}



//EspacioDeTrabajoDAL regEspacio;
//ReservasDAL regReservas;
//
//    int CantidadEspacios=regEspacio.cantidadEspacios();
//    int CantidadReservas=regReservas.cantidadReservas();
//    int DisponibilidadReal=0;
//    int EspacioSelec=0;
//    EspacioDeTrabajoDTO* Espacios=new EspacioDeTrabajoDTO[CantidadEspacios];
//
//    for(int i=0;i<CantidadEspacios;i++){
//
//       Espacios[i]=regEspacio.LeerEspaciodeTrabajo(i);
//    }
//    ReservaDTO* Reservas= new ReservaDTO [CantidadReservas];
//
//    for(int j=0;j<CantidadReservas;i++){
//        Reservas[i]=regReservas.LeerReservas(i);
//    }
//
//    for(int i=0;i<CantidadEspacios;i++){
//        if(regEspacio.getTipo()==espacio)
//            {
//            EspacioSelec=regEspacio.getTipo();
//            DisponibilidadReal=regEspacio.getDisponibilidad();
//            }
//
//            int Cont=0;
//
//         for(int j=0;j<CantidadReservas;i++){
//
//
//            if(regReservas.getEspacio()==EspacioSelec&&
//            regReservas.getFecha().getDia()==select){
//
//            DisponibilidadReal=regEspacio.getDisponibilidad();
//            Cont++;
//            }
//
//
//         }
//    }
//}
//
//          if(Cont<=DisponibilidadReal)
//{
//    ReservaDTO.setNumero(dni);
//    ReservaDTO.setLegajo(Legajo);
//    ReservaDTO.setEspacioTrabajo(espacio);
//    ReservaDTO.setFecha(Fecha);
//    ReservaDTO.setEstado(true);
//
//FUNCION GUARDAR EN EL ARCHIVO//
//
//}
