#ifndef FUNCIONES_USER_H_INCLUDED
#define FUNCIONES_USER_H_INCLUDED

#include "FUNCIONES_FRONT.h"

bool validarDni(int dni);
void salirSistemaUser();
int listarReservasFuturas(int dni);
int listarHistorialReservas(int dni);

#endif // FUNCIONES_USER_H_INCLUDED
