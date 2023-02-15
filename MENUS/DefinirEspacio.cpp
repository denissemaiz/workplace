#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_FRONT.h"
#include "MENUS.h"
#include "FUNCIONES_ADMIN.h"

void llamarDefinirEspacio(int tipoEspacio);

void cuadroLimitarEspacio(int opc)
{
    system("cls");
    const char *opciones[] = {"DESK","SALA DE REUNIONES", "ESTACIONAMIENTO", "COMEDOR","VOLVER AL MENU PRINCIPAL"};

    mostrar_mensaje ("* SELECCIONE EL ESPACIO A DEFINIR *", 40, 5);
    mostrar_mensaje ("___________________________________", 40, 6);

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
            case 0:      ///DESK
                system("cls");
                llamarDefinirEspacio(y);
                break;
            case 1:       ///SALA DE REUNIONES
                system("cls");
                llamarDefinirEspacio(y);
                break;
            case 2:       ///ESTACIONAMIENTO
                system("cls");
                llamarDefinirEspacio(y);
                break;
            case 3:     ///COMEDOR
                system("cls");
                llamarDefinirEspacio(y);
                break;
            case 4:     ///VOLVER A MENU ADMIN
                system("cls");
                menuAdmin();
                break;
            }
            break;
        }
    }
    while(op!=0);

    system("pause>nul");
    return;
}

void llamarDefinirEspacio(int tipoEspacio)
{
    if(definirEspacios(tipoEspacio))
    {
        mostrar_mensaje ("*** ESPACIO DEFINIDO *** ", 40, 20);
        mostrar_mensaje (" MUCHAS GRACIAS  ", 44, 22);
        getch();
        system("cls");
        menuAdmin();
    }
    else
    {
        system("cls");
        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("UPS. ALGO SALIO MAL...", 20, 14);
        getch();
        system("cls");
        menuAdmin();
    }
}
