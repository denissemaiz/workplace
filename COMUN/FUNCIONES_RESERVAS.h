#ifndef FUNCIONES_RESERVAS_H_INCLUDED
#define FUNCIONES_RESERVAS_H_INCLUDED

#include "../MENUS/MENUS.h"
#include "FUNCIONES_FRONT.h"

int contarReservas(int espacio, Fecha fecha);
int incrementarNroReserva();
bool consultarDisponibilidad(int espacio, Fecha fecha);
void confirmacionReserva(int dni, int espacio, Fecha fecha);
bool chequearNroReserva(int nroReserva, int dni);
int listarPorDni();
int listarPorLegajo();
int listarPorEspacio();
/**/  //FALTAN:
void anularReserva(int dni);
void confirmacionAnulacion();

#endif // FUNCIONES_RESERVAS_H_INCLUDED
