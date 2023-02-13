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


void Respaldos()
{
    system("cls");
    int n=4;
    const char *opciones[] = {"RESERVAS","LISTADO DE EMPLEADOS", "LISTADO DE ESPACIOS", "VOLVER AL MENU PRINCIPAL"};

        mostrar_mensaje ("**** ARCHIVOS A RESPALDAR: ****", 40, 5);
        mostrar_mensaje ("-------------------------------", 40, 6);

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

            if (y>4)
            {
                y=4;
            }
            break;

        case 1:   /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {
            case 0:      /// RESERVAS
                system("cls");



             break;

            case 1:       /// LISTADO DE EMPLEADOS
                system("cls");

                break;

            case 2:       /// LISTADOS DE ESPACIOS
                system("cls");

                break;

            case 3:     /// VOLVER AL MENU PRINCIPAL
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
