#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_USER.h"
#include "MENUS.h"
#include "Fecha.h"

void cuadroSeleccionDia(int dni, int espacio)
{
    system("cls");
    rectangulo (2, 2, 100, 25);

    mostrar_mensaje ("*** POR FAVOR SELECCIONE EL DIA A RESERVAR: ***", 30, 5);
    mostrar_mensaje ("-----------------------------------------------", 30, 6);

    Fecha obj;
    Fecha vecFechas[14]= {};
    int select;
    bool disponibilidad=false;

    for(int i=0; i<14; i++)
    {
        obj.operator++();
        vecFechas[i] = obj;
    }

    for(int j=0; j<14; j++)
    {
        rlutil::locate(40,8+j);
        vecFechas[j].Mostrar();
        rlutil::locate(36,8+j);
        cout << j+1 <<"- ";
    }

    mostrar_mensaje ("POR FAVOR INGRESE EL DIA A RESERVAR: ", 30, 25);
    rlutil::locate(67,25);
    cin>>select;
    if(select<1 || select>14)
    {
        system("cls");
        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("**** LA OPCION INGRESADA NO ES VALIDA ****", 30, 15);
        system("pause>nul");
        menuUser(dni);
    }
    disponibilidad = consultarDisponibilidad(espacio, vecFechas[select-1]);
    if(!disponibilidad)
    {
        fechaNoDisponible(dni, espacio);
    }
    else
    {
        reciboConfirmacionReserva(espacio, vecFechas[select-1]);
    }
}
