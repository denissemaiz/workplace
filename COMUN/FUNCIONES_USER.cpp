#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_USER.h"
#include "FUNCIONES_FRONT.h"
#include "ReservasDAL.h"
#include "ReservaDTO.h"
#include "Fecha.h"

bool validarDni(int dni)
{
    int cifras=0;

    while(dni > 0)
    {
        dni = dni / 10;
        cifras++;
    }

    if(cifras==8)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int contarReservas(int espacio, Fecha fecha) ///cuenta reservas de x dia en x espacio
{
    ReservasDAL regReserva;
    int cantReservas=0;

    int tamReservas=regReserva.getCantidad();
    ReservaDTO* vecReservas= new ReservaDTO[tamReservas];

    regReserva.leerTodos(vecReservas, tamReservas);

    for(int i=0; i<tamReservas; i++)
    {
        if(vecReservas[i].getEspacioTrabajo()==espacio
                && vecReservas[i].getFecha().operator==(fecha))
        {
            cantReservas++;
        }
    }

    return cantReservas;
}

int incrementarNroReserva()
{
    ReservasDAL regReserva;
    int ultReserva;

    ultReserva = regReserva.getCantidad();

    return ultReserva++;
}

void SalirSistemaUser()
{
    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****   MUCHAS GRACIAS POR USAR NUESTRO SISTEMA *****", 28, 10);
    mostrar_mensaje ("By CIBERNAUTAS", 68, 20);
}

