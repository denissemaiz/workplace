#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_FRONT.h"
#include "MENUS.h"
#include "Fecha.h"


void cuadroSeleccionarEspacio(int dni)
{
    system("cls");
    rectangulo (2, 2, 100, 20);

    const char *opciones[] = {"DESK","SALA DE REUNIONES", "ESTACIONAMIENTO", "COMEDOR"};

    mostrar_mensaje ("* SELECCIONE UN ESPACIO A RESERVAR *", 30, 5);
    mostrar_mensaje ("____________________________________", 30, 6);

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
                cuadroSeleccionDia(dni, y);
                break;
            case 1:       ///SALA DE REUNIONES
                cuadroSeleccionDia(dni, y);
                break;
            case 2:       ///ESTACIONAMIENTO
                cuadroSeleccionDia(dni, y);
                break;
            case 3:     ///COMEDOR
                cuadroSeleccionDia(dni, y);
                break;
            }
        }
    }
    while(op!=0);
    system("pause>nul");
}
