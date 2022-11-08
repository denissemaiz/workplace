#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

#include "rlutil.h"
#include "FUNCIONES.h"
#include "Fecha.h"

void CuadroSeleccionDia()
{

    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje (" POR FAVOR SELECCIONE EL DIA A RESERVAR:", 30, 5);


}
