#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Fecha.h"

void mostrar_mensaje(string texto, int x, int y);
void rectangulo(int posx, int posy, int ancho, int alto);
void CuadroIncio();
void CuadroReservaEspacio();
void CuadroSeleccionDia();
void CuadroConfirmacionFecha();
void CuadroConfirmacionReserva();
void ReciboConfirmacionReserva();
void FechaNoDisponible();
void reservaDesde(Fecha obj);
void reservaHasta(Fecha obj);
void AnularReserva();
void ConfirmacionAnulacion();
void HistorialReservas();
void CargarEmpleados();
void showItem (const char* text, int posx, int posy, bool selected);
void menuUser();


#endif // FUNCIONES_H_INCLUDED
