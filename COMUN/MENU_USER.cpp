#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

#include "rlutil.h"
#include "FUNCIONES.h"
#include "Fecha.h"

void CuadroMenu()
{
int op;

    rectangulo (2, 2, 100, 30);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje (" ¿QUE DESEAS HACER?", 40, 5);
    mostrar_mensaje ("_____________________", 40, 6);

    mostrar_mensaje ("1-RESERVAR", 10, 12);
    mostrar_mensaje ("2-ANULAR RESERVA", 10, 14);
    mostrar_mensaje ("3-CONSULTAR MI HISTORIAL", 10, 16);
    mostrar_mensaje ("4-SALIR", 10, 18);

    mostrar_mensaje ("SELECCIONE UNA OPCION", 38, 23);
    rlutil::  locate (40,25);
    cin >>op;

}
