#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES.h"
#include "Fecha.h"

void mostrar_mensaje (string texto, int x, int y)
{
    rlutil::  locate (x,y);
    cout <<texto;
}


void rectangulo (int posx, int posy, int ancho, int alto){

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


void cuadroConfirmacionReserva()
{
    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje (" USTED ESTA RESERVANDO EL DIA:", 30, 5);

    mostrar_mensaje (" ESPACIO:", 10, 8);
    mostrar_mensaje (" DIA:", 10, 10);
    mostrar_mensaje (" HORARIO DE INGRESO:", 10, 12);
    mostrar_mensaje (" HORARIO DE EGRESO:", 10, 14);
    mostrar_mensaje (" PISO/SECTOR DONDE SE REALIZO LA RESERVA:", 10, 16);
    mostrar_mensaje (" ¿CONFIRMA LA RESERVA? :", 10, 18);
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
