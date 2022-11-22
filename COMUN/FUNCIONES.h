#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Fecha.h"

void mostrar_mensaje(string texto, int x, int y);
void rectangulo(int posx, int posy, int ancho, int alto);

void cuadroIncio();
void cuadroReservaEspacio();
void cuadroSeleccionDia();
void cuadroConfirmacionFecha();
void cuadroConfirmacionReserva();
void reciboConfirmacionReserva();
void fechaNoDisponible();
void anularReserva();
void confirmacionAnulacion();
void historialReservas();
void cargarEmpleados();

void showItem (const char* text, int posx, int posy, bool selected);
void menuUser();


#endif // FUNCIONES_H_INCLUDED
