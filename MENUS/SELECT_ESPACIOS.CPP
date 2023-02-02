#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_USER.h"
#include "Fecha.h"


void cuadroReservaEspacio()
{
    system("cls");
    rectangulo (2, 2, 100, 20);

    int n=4;
    const char *opciones[] = {"DESK","SALA DE REUNIONES", "ESTACIONAMIENTO", "COMEDOR"};

    mostrar_mensaje ("__________________________", 40, 3);
    mostrar_mensaje ("* SELECCIONE UNA OPCION *", 40, 5);
    mostrar_mensaje ("__________________________", 40, 6);

    int op=1, y=0;
    int espacio;

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

        case 1: //ENTER
            cuadroConfirmacionFecha(y);
            break;
            ///esto esta raro....... /**/
            switch(y)
            {
            case 3:
                op=0;
            }
            break;

        default:
            break;
        }
    }

    while(op!=0);
    system("pause>nul");
}
