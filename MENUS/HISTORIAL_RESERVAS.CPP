#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_ADMIN.h"
#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_USER.h"
#include "Fecha.h"
#include "MENUS.h"


void historialReservas(int dni)
{
    system("cls");

    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 20);

    mostrar_mensaje ("**** ESTAS CONSULTANDO TUS RESERVAS ****", 33, 5);
    mostrar_mensaje ("-------------------------------------", 33, 6);
    int n=4, op=-1, y=0;

    const char *opciones[] = {"RESERVAS PASADAS","RESERVAS FUTURAS","RESERVAS ANULADAS","VOLVER AL MENU PRINCIPAL"};

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
            cout <<"    " <<endl;
            y--;

            if (y<0)
            {
                y=0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(26,10+y);
            cout <<"    " <<endl;
            y++;

            if (y>3)
            {
                y=3;
            }
            break;

        case 1: //ENTER

            switch(y)
            {
            case 0:
                system("cls");
                {

                    mostrar_mensaje ("*PASADAS: ", 30, 4);
                    mostrar_mensaje ("---------", 30, 5);
                    ///ACA VA LA FUNCION DE BUSQUEDA-HACER
                }

                break;

            case 1:

            {

                mostrar_mensaje ("*FUTURAS: ", 30, 4);
                mostrar_mensaje ("---------", 30, 5);
                ///ACA VA LA FUNCION DE BUSQUEDA-HACER
            }

            break;

            case 2:
                system("cls");
                {
                    mostrar_mensaje ("*ANULADAS: ", 30, 4);
                    mostrar_mensaje ("---------", 30, 5);
                    ///ACA VA LA FUNCION DE BUSQUEDA-HACER
                }

                break;

            case 3:
             system("cls");
            {
                menuUser(dni);
            }

            break;
            }
        }
    }
    while(op!=0);
    system("pause>nul");

}
