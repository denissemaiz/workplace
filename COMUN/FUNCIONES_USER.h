#ifndef FUNCIONES_USER_H_INCLUDED
#define FUNCIONES_USER_H_INCLUDED

#include "Fecha.h"

bool validarDni(int dni);
int contarReservas(int espacio, Fecha fecha);
bool reciboConfirmacionReserva(int espacio, Fecha fecha);
void fechaNoDisponible();
void anularReserva(int dni);
void confirmacionAnulacion();
void historialReservas(int dni);
void SalirSistemaUser();
int incrementarNroReserva();



#endif // FUNCIONES_USER_H_INCLUDED
