#include <iostream>
#include<cstdlib>
#include<cstring>
#include<windows.h>
#include<conio.h>

using namespace std;

#include "PersonaDTO.h"
#include "PersonaDAL.h"
#include "EmpleadoDTO.h"
#include "EmpleadoDAL.h"
#include "FUNCIONES.h"
#include "rlutil.h"

int main()
{

system("color 8F");

///PANTALLA INICIO


CuadroIncio();

_getch();
system("cls");

///PANTALLA MENU


CuadroMenu();




_getch();
system("cls");

///PANTALLA SELECCION DE ESPACIO


CuadroReservaEspacio();

_getch();
system("cls");

///PANTALLA SELECCION DE DIA

CuadroSeleccionDia();

_getch();
system("cls");

///PANTALLA CONFIRMACION RESERVA

CuadroConfirmacionReserva();


_getch();
system("cls");







_getch();
rlutil::  locate (2,30);


    return 0;
}
