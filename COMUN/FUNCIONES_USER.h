#ifndef FUNCIONES_USER_H_INCLUDED
#define FUNCIONES_USER_H_INCLUDED

#include "FUNCIONES_FRONT.h"

bool validarDni(int dni);
int listarReservasFuturas(int dni);
int listarHistorialReservas(int dni);
bool chequearEmpleado(int dni);
int ingresarNroReserva();
void anularReserva(int dni);

#endif // FUNCIONES_USER_H_INCLUDED
