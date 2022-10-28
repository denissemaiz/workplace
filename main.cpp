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
#include "EspacioDeTrabajoDTO.h"

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

Fecha obj;
int d, m, a;


rlutil::  locate (20,10);
cout <<"Desde: ";
rlutil::  locate (27,10);
reservaDesde(obj);


rlutil::  locate (40,10);
cout <<"Hasta: ";
rlutil::  locate (48,10);
reservaHasta(obj);

rlutil::  locate (30,15);
cout <<"Por Favor Ingrese el dia a reservar: ";
cin >> d;

rlutil::  locate (30,17);
cout <<"Por Favor Ingrese el mes a reservar: ";
cin >> m;
rlutil::  locate (30,19);
cout <<"Por Favor Ingrese el año a reservar: ";
cin >> a;


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
