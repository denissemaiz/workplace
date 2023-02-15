#ifndef FUNCIONES_USER_H_INCLUDED
#define FUNCIONES_USER_H_INCLUDED

#include "Fecha.h"

int contarReservas(int espacio, Fecha fecha);
void reciboConfirmacionReserva(int espacio, Fecha fecha);
void fechaNoDisponible();
void anularReserva(int dni);
void confirmacionAnulacion();
void historialReservas(int dni);
void SalirSistemaUser();



#endif // FUNCIONES_USER_H_INCLUDED
