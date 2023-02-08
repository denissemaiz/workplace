#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_USER.h"
#include "FUNCIONES_FRONT.h"
#include "MENUS.h"
#include "Fecha.h"

void cuadroSeleccionDia(int espacio)
{
    system("cls");
    rectangulo (2, 2, 100, 20);

    mostrar_mensaje (" POR FAVOR SELECCIONE EL DIA A RESERVAR:", 30, 5);
    mostrar_mensaje ("----------------------------------------", 30, 6);

    Fecha obj;
    Fecha vecFechas[14]={};

    for(int i=1; i<15; i++)
    {
        obj.operator++();
        vecFechas[i-1] = obj;
    }

    for(int j=0; j<14; j++){
        rlutil::locate(30,7+j);
        vecFechas[j].Mostrar();
    }
}

/**/
void cuadroSeleccionarSector(int espacio)
{
    system("cls");
    rectangulo (2, 2, 100, 20);

    mostrar_mensaje ("ESTAS POR RESERVAR UN ESPACIO EN: ", 49, 4);
    mostrar_mensaje ("DIA DE LA RESERVA: ", 49, 5);

    int n=5;
    const char *opciones[] = {"ADMINISTRACION Y RRHH","VENTAS Y MARKETING", "PRODUCCION", "CONTABILIDAD Y FINANZAS", "DIRECCION"};

    mostrar_mensaje ("-------------------------------------", 8, 8);
    mostrar_mensaje ("AREA DONDE QUIERE RESERVAR: ", 8, 9);
    mostrar_mensaje ("-------------------------------------", 8, 10);
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],10,12,y==0);
        showItem (opciones[1],10,13,y==1);
        showItem (opciones[2],10,14,y==2);
        showItem (opciones[3],10,15,y==3);
        showItem (opciones[4],10,16,y==4);

        rlutil::locate(6,12+y);
        cout <<"==> " <<endl;

        switch(rlutil::getkey())
        {
        case 14: //UP
            rlutil::locate(6,12+y);
            cout <<"   " <<endl;
            y--;

            if (y<0)
            {
                y=0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(6,12+y);
            cout <<"   " <<endl;
            y++;

            if (y>4)
            {
                y=4;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {
            case 0:         ///ADMINISTRACION Y RRHH
                reciboConfirmacionReserva();
                break;
            case 1:         ///VENTAS Y MARKETING
                reciboConfirmacionReserva();
                break;
            case 2:         ///PRODUCCION
                reciboConfirmacionReserva();
                break;
            case 3:         ///CONTABILIDAD Y FINANZAS
                reciboConfirmacionReserva();
                break;
            case 4:        ///DIRECCION
                reciboConfirmacionReserva();
                break;
            }
        }
    }
    while(op!=0);
    system("pause>nul");
}

void reciboConfirmacionReserva()
{
    system("cls");
    rectangulo (2, 2, 100, 20);

    mostrar_mensaje ("USTED RESERVO:  ", 40, 4);
    mostrar_mensaje ("ESPACIO: ", 20, 7);
    mostrar_mensaje ("SECTOR: ", 20, 8);
    mostrar_mensaje ("DIA: ", 20, 9);
    mostrar_mensaje ("DESDE LAS: ", 20, 10);
    mostrar_mensaje ("HASTA LAS: ", 20, 11);
    mostrar_mensaje ("CONFIRMA LA RESERVA: ", 40, 18);

    int n=2, op=1, y=0;
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
                break;
            case 1:      /// NO CONFIRMA
                confirmacionAnulacion();
                break;
            }
        }
    }
    while(op!=0);
    system("pause>nul");
}

void fechaNoDisponible()
{
    system("cls");
    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::RED);
    mostrar_mensaje ("**   LO SENTIMOS NO HAY MAS DISPONIBILIDAD PARA LA FECHA SELECCIONADA  **  ", 19, 6);

    int n=2, op=1, y=0;;
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

        case 1:            /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1)

            switch(y)
            {
            case 0:     ///VOLVER A CALENDARIO
                break;
            case 1:     ///MENU PRINCIPAL
                //  menuUser();
                break;
            }
        }
    }

    while(op!=0);
    system("pause>nul");
}
