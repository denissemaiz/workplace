#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_FRONT.h"
#include "MENUS.h"
#include "FUNCIONES_ADMIN.h"
#include "Fecha.h"


void cuadroLimitarEspacio(int opc)
{
    int n=4;
    const char *opciones[] = {"DESK","SALA DE REUNIONES", "ESTACIONAMIENTO", "COMEDOR"};

    mostrar_mensaje ("___________________________________", 40, 3);
    mostrar_mensaje ("* SELECCIONE UN ESPACIO *", 40, 5);
    mostrar_mensaje ("__________________________________", 40, 6);

    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);
        showItem (opciones[3],30,13,y==3);

        rlutil::locate(26,10+y);
        cout <<"==> " <<endl;

        switch(rlutil::getkey())
        {
        case 14: //UP
            rlutil::locate(26,10+y);
            cout <<"   " <<endl;
            y--;

            if (y<0)
            {
                y=0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(26,10+y);
            cout <<"   " <<endl;
            y++;

            if (y>3)
            {
                y=3;
            }
            break;

        case 1:   /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {
            case 0:      ///DESK
                system("cls");
                if(opc==3)
                {
                    if (definirEspacios(y))
                    {
                        rlutil::  locate (20,23);
                        cout<<"ESPACIO DEFINIDO.";
                    }
                    else
                    {
                        system("cls");
                        rectangulo (2, 2, 100, 26);
                        rlutil::setColor(rlutil::YELLOW);
                        mostrar_mensaje ("UPS. ALGO SALIO MAL...", 20, 14);
                    }
                }
                else if(opc==4)
                {
                    limitarEspacios(y);
                }
                break;

            case 1:       ///SALA DE REUNIONES
                system("cls");
                if(opc==3)
                {
                    if ( definirEspacios(y))
                    {
                        rlutil::  locate (20,23);
                        cout<<"ESPACIO DEFINIDO.";
                    }
                    else
                    {
                        system("cls");
                        rectangulo (2, 2, 100, 26);
                        rlutil::setColor(rlutil::YELLOW);
                        mostrar_mensaje ("UPS. ALGO SALIO MAL...", 20, 14);
                    }
                }
                else if(opc==4)
                {
                    limitarEspacios(y);
                }
                break;
            case 2:       ///ESTACIONAMIENTO
                system("cls");
                if(opc==3)
                {
                    if (definirEspacios(y))
                    {
                        rlutil::  locate (20,23);
                        cout<<"ESPACIO DEFINIDO.";
                    }
                    else
                    {
                        system("cls");
                        rectangulo (2, 2, 100, 26);
                        rlutil::setColor(rlutil::YELLOW);
                        mostrar_mensaje ("UPS. ALGO SALIO MAL...", 20, 14);
                    }
                }
                else if(opc==4)
                {
                    limitarEspacios(y);
                }
                break;
            case 3:     ///COMEDOR
                system("cls");
                if(opc==3)
                {
                    if ( definirEspacios(y))
                    {
                        rlutil::  locate (20,23);
                        cout<<"ESPACIO DEFINIDO.";
                    }
                    else
                    {
                        system("cls");
                        rectangulo (2, 2, 100, 26);
                        rlutil::setColor(rlutil::YELLOW);
                        mostrar_mensaje ("UPS. ALGO SALIO MAL...", 20, 14);
                    }
                }
                else if(opc==4)
                {
                    limitarEspacios(y);
                }
                break;
            }
        }
    }

    while(op!=0);
    system("pause>nul");
}
