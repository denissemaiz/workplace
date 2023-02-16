#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_USER.h"
#include "FUNCIONES_ADMIN.h"

#include "Fecha.h"

void menuIncio();
void menuAdmin();
void menuUser(int dni);
void menuSeleccionarEspacio(int dni);
void menuSeleccionarDia(int dni, int espacio);
bool menuConfirmarReserva(int espacio, Fecha fecha);
/*void cuadroConfirmacionReserva();*/  /**/
void menuLimitarEspacio();
bool menuModificarDatos(int nroRegistro);
void menuFechaNoDisponible(int dni, int espacio);


#endif // MENUS_H_INCLUDED
