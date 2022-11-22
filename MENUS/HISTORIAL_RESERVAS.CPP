#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES.h"
#include "Fecha.h"


void historialReservas()
{
    system("cls");

    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 20);

    mostrar_mensaje (" ESTAS SON TUS RESERVAS ", 33, 5);
    mostrar_mensaje ("*PASADAS: ", 10, 8);
    mostrar_mensaje ("---------", 10, 9);
    mostrar_mensaje ("*FUTURAS: ", 10, 12);
    mostrar_mensaje ("---------", 10, 13);

    int n=2, op=1, y=0;;
    const char *opciones[] = {"VOLVER AL MENU PRINCIPAL","SALIR DEL SISTEMA"};

    rlutil::hidecursor();

    do
    {
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],20,15,y==0);
        showItem (opciones[1],20,16,y==1);

        rlutil::locate(16,15+y);
        cout <<"==> " <<endl;

        switch(rlutil::getkey())
        {
        case 14: //UP
            rlutil::locate(16,15+y);
            cout <<"    " <<endl;
            y--;

            if (y<0)
            {
                y=0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(16,15+y);
            cout <<"    " <<endl;
            y++;

            if (y>1)
            {
                y=1;
            }
            break;

        case 1: //ENTER
            historialReservas();
            break;

            switch(y)
            {
            case 2:
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
