#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "Fecha.h"

void menuIncio();
void menuAdmin();
void menuUser(int dni);
void cuadroSeleccionarEspacio(int dni);
void cuadroSeleccionarSector(int espacio);
void cuadroSeleccionDia(int dni, int espacio);
bool consultarDisponibilidad(int espacio, Fecha fecha);
void cuadroConfirmacionReserva();
void cuadroLimitarEspacio(int);
bool menuModificarDatos(int nroRegistro);
void fechaNoDisponible(int dni, int espacio);
void confirmacionReserva(int dni, int espacio, Fecha fecha);


#endif // MENUS_H_INCLUDED
