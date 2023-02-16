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
int totalReservasUltMes();
int totalReservasAnuladasUltMes();
float porcentajeReservasAnuladas();
int totalReservasAdmRRHH();
int totalReservasMarkVentas();
int totalReservasProdSist();
int totalReservasContabFinanzas();
int totalReservasGerenDirecc();

#endif // FUNCIONES_RESERVAS_H_INCLUDED
