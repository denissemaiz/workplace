#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

#include "rlutil.h"
#include "FUNCIONES.h"
#include "Fecha.h"


void CuadroIncio()
{

    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("___________________________", 40, 3);
    mostrar_mensaje ("**BIENVENIDO A WORKPLACE**" ,40, 5);
    mostrar_mensaje ("___________________________", 40, 6);

    int dni;
    rlutil::  locate (30,12);
    cout <<"INGRESE SU DNI: ";
    rlutil::  locate (47,12);
    cin >>dni;
}
