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
#include "EspacioDeTrabajo.h"

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


rlutil::  locate (25,10);
cout <<"Desde: ";
rlutil::  locate (32,10);
reservaDesde(obj);


rlutil::  locate (50,10);
cout <<"Hasta: ";
rlutil::  locate (57,10);
reservaHasta(obj);

rlutil::  locate (23,13);
cout <<"**POR FAVOR INGRESAR FECHA QUE DESEA RESERVAR** ";
rlutil::  locate (23,14);
cout <<"----------------------------------------------- ";
rlutil::  locate (27,16);
cout <<"DIA: ";
cin >> d;

rlutil::  locate (27,17);
cout <<"MES: ";
cin >> m;
rlutil::  locate (27,18);
cout <<"ANIO: ";
cin >> a;


_getch();
system("cls");

///PANTALLA CONFIRMACION RESERVA

CuadroConfirmacionReserva();


_getch();
system("cls");

///PANTALLA ANULACION RESERVA

AnularReserva();

_getch();
system("cls");

///PANTALLA CONFIRMACION RESERVA

ConfirmacionAnulacion();

_getch();
system("cls");

///PANTALLA HISTORIAL

HistorialReservas();

_getch();
system("cls");





_getch();
rlutil::  locate (2,30);


    return 0;
}
