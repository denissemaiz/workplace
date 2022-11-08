#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

#include "rlutil.h"
#include "FUNCIONES.h"
#include "Fecha.h"


void HistorialReservas()
{
    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 40);

    rlutil::setColor(rlutil::WHITE);
    rectangulo (28, 4, 33, 1);
    mostrar_mensaje (" ESTAS SON TUS RESERVAS ", 33, 5);


    mostrar_mensaje ("*PASADAS: ", 10, 8);
    mostrar_mensaje ("---------", 10, 9);

    mostrar_mensaje ("*FUTURAS: ", 10, 20);
    mostrar_mensaje ("---------", 10, 21);


    mostrar_mensaje (" VOLVER AL MENU PRINCIPAL: ", 10, 30);
    mostrar_mensaje (" SALIR DEL SISTEMA: ", 10, 32);

}
