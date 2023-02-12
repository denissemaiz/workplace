#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "MENUS.h"
#include "FUNCIONES_ADMIN.h"
#include "FUNCIONES_USER.h"
#include "FUNCIONES_FRONT.h"
#include "Fecha.h"


void ModificarDatos()
{
    system("cls");
    int n=7;
    const char *opciones[] = {"NOMBRE","APELLIDO", "DNI", "MAIL", "TELEFONO", "SECTOR", "DAR DE BAJA", "VOLVER AL MENU PRINCIPAL"};

        mostrar_mensaje ("* MODIFICAR DATOS DEL EMPLEADO *", 40, 4);
        mostrar_mensaje ("--------------------------------", 40, 5);

        rlutil::saveDefaultColor();
        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);

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
        showItem (opciones[4],30,14,y==4);
        showItem (opciones[5],30,15,y==5);
        showItem (opciones[6],30,16,y==6);
        showItem (opciones[7],30,17,y==7);

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

            if (y>7)
            {
                y=7;
            }
            break;

        case 1:   /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {
            case 0:      /// SETEAR NOMBRE
                system("cls");



             break;

            case 1:       /// SETEAR APELLIDO
                system("cls");

                break;

            case 2:       /// SETEAR DNI
                system("cls");

                break;

            case 3:     /// SETEAR MAIL
                system("cls");


                break;

            case 4:     /// SETEAR TELEFONO
                system("cls");


                break;
                 case 5:     /// SETEAR SECTOR
                system("cls");


                break;
                 case 6:     /// SETEAR DAR DE BAJA
                system("cls");


                break;

                case 7:     /// VOLVER AL MENU PRINCIPAL
                system("cls");
                                {
                        menuAdmin();
                                }

                break;
            }
        }
    }

    while(op!=0);
    system("pause>nul");
}
