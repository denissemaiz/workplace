#include "FUNCIONES_FRONT.h"
#include "MENUS.h"

void menuFechaNoDisponible(int dni, int espacio)
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
                menuSeleccionarDia(dni, espacio);
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
