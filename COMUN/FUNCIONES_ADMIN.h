#ifndef FUNCIONES_ADMIN_H_INCLUDED
#define FUNCIONES_ADMIN_H_INCLUDED

#include "../MENUS/MENUS.h"
#include "FUNCIONES_FRONT.h"

int agregarEmpleado();
bool modificarEmpleado();
bool listarEmpleados();
bool definirEspacios(int espacio);
bool listarEspacios();
/**/ //FALTAN:
void consultasReservas();
void Informes();
void Respaldos();
void InformePlantilla();
void InformeDesk();
void InformeSalaReuniones();
void InformeEstacionamiento();
void InformeComedor();

#endif // FUNCIONES_ADMIN_H_INCLUDED
