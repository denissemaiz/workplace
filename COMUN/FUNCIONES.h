#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Fecha.h"

void mostrar_mensaje(string texto, int x, int y);
void rectangulo(int posx, int posy, int ancho, int alto);
void CuadroIncio();
void CuadroMenu();
void CuadroReservaEspacio();
void CuadroSeleccionDia();
void CuadroConfirmacionReserva();
void reservaDesde(Fecha obj);
void reservaHasta(Fecha obj);
void AnularReserva();
void ConfirmacionAnulacion();
void HistorialReservas();



#endif // FUNCIONES_H_INCLUDED
