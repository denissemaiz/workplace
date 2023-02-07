#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_USER.h"
#include "FUNCIONES_FRONT.h"
#include "Fecha.h"

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

void SalirSistemaUser()
{
    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje (" ----------------------------------------", 30, 15);
    mostrar_mensaje (" MUCHAS GRACIAS POR VISITARNOS", 30, 15);
    mostrar_mensaje (" ----------------------------------------", 30, 15);
}
