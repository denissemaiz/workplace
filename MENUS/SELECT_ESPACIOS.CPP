#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

#include "rlutil.h"
#include "FUNCIONES.h"
#include "Fecha.h"



void CuadroReservaEspacio()
{

    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje (" POR FAVOR SELECCIONE EL ESPACIO A RESERVAR", 30, 5);

    mostrar_mensaje ("1-DESK", 10, 8);
    mostrar_mensaje ("2-SALA DE REUNIONES", 10, 10);
    mostrar_mensaje ("3-ESTACIONAMIENTO", 10, 12);
    mostrar_mensaje ("4-COMEDOR", 10, 14);

}
