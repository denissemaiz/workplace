#include "../MENUS/MENUS.h"
#include "FUNCIONES_FRONT.h"

void mostrar_mensaje (string texto, int x, int y)
{
    rlutil::  locate (x,y);
    cout <<texto;
}

void rectangulo (int posx, int posy, int ancho, int alto)
{

/// ABAJO
    for (int x= 1; x <=ancho; x++)
    {
        rlutil::locate( x+ posx, posy);
        cout << (char)205;

        rlutil::locate( x+ posx, posy+alto+1);
        cout << (char)205;
    }

///ANCHO
    for (int y= 1; y <=alto; y++)
    {
        rlutil::locate( posx,  posy+y);
        cout << (char)186;

        rlutil::locate( posx+ancho+1, posy+y);
        cout << (char)186;

    }

///ESQUINAS
    rlutil::locate( posx, posy);
    cout << (char)201;

    rlutil::locate( posx, posy+alto +1);
    cout << (char)200;

    rlutil::locate( posx +ancho +1, posy);
    cout << (char)187;

    rlutil::locate( posx +ancho +1, posy+ alto +1);
    cout << (char)188;
}

///MENU MOVIL
void showItem (const char* text, int posx, int posy, bool selected)
{
    if (selected)
    {
        rlutil::setBackgroundColor(rlutil::CYAN);
        rlutil::  locate (posx -3,posy);
        cout <<"==>";
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::DARKGREY);
        rlutil::  locate (posx -3,posy);
        cout <<"==>";
    }
    rlutil::locate(posx, posy);
    cout << text <<endl;
    rlutil::setBackgroundColor(rlutil::DARKGREY);
}

void showItemDia (const char* text, int posx, int posy, bool selected)
{
    rlutil::locate(posx, posy);
    cout << text <<endl;
    rlutil::setBackgroundColor(rlutil::DARKGREY);
}

bool seleccionarSiNo()
{
    int op=1, y=0;
    const char *opciones[] = {"SI","NO"};
    rlutil::hidecursor();

    do
    {
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],50,18,y==0);
        showItem (opciones[1],50,19,y==1);

        rlutil::locate(46,18+y);
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
            case 0:     /// SI
                return true;
                break;
            case 1:      /// NO
                return false;
                break;
            }
        }
    }
    while(op!=0);
    system("pause>nul");
    return false;
}

void salirSistemaUser()
{
    rectangulo (2, 2, 100, 20);
    mostrar_mensaje ("*****   MUCHAS GRACIAS POR USAR NUESTRO SISTEMA *****", 28, 10);
    mostrar_mensaje ("By CIBERNAUTAS", 68, 20);
    getch();
    menuIncio();
}
