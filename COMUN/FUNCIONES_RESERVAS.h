#ifndef FUNCIONES_RESERVAS_H_INCLUDED
#define FUNCIONES_RESERVAS_H_INCLUDED

#include "../MENUS/MENUS.h"
#include "FUNCIONES_FRONT.h"
#include "Fecha.h"

int contarReservas(int espacio, Fecha fecha);
int incrementarNroReserva();
bool consultarDisponibilidad(int espacio, Fecha fecha);
void confirmacionReserva(int dni, int espacio, Fecha fecha);
/**/  //FALTAN:
void anularReserva(int dni);
void confirmacionAnulacion();
void historialReservas(int dni);

#endif // FUNCIONES_RESERVAS_H_INCLUDED
