#include "FUNCIONES_USER.h"

#include "ReservaDTO.h"
#include "ReservasDAL.h"
#include "EmpleadoDAL.h"

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

void salirSistemaUser()
{
    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****   MUCHAS GRACIAS POR USAR NUESTRO SISTEMA *****", 28, 10);
    mostrar_mensaje ("By CIBERNAUTAS", 68, 20);
}

int listarReservasFuturas(int dni)
{
    ReservasDAL regReserva;
    EmpleadoDAL regEmpleado;

    int legajo, contador=0;
    Fecha fechaHoy;

    /*fechaHoy.Mostrar();
    getch();

    fechaHoy.operator++();
    fechaHoy.operator++();

    fechaHoy.Mostrar();
    getch();*/

    int cantidad=regReserva.getCantidad();
    ReservaDTO* vecReserva= new ReservaDTO[cantidad];

    if (cantidad > 0)
    {
        legajo = regEmpleado.buscarLegajo(dni);
        regReserva.leerTodos(vecReserva, cantidad);
        for(int i=0; i<cantidad; i++)
        {
            if(vecReserva[i].getLegajo()==legajo
                    && vecReserva[i].getEstado()==true
                    && vecReserva[i].getFecha().operator>=(fechaHoy))
            {
                contador++;
                system("cls");
                rectangulo (2, 2, 100, 20);
                mostrar_mensaje ("***   ANULANDO RESERVAS   ***", 39, 4);
                mostrar_mensaje ("     --------------------  ", 39, 5);
                mostrar_mensaje ("ESTAS SON TUS RESERVAS: ", 20, 9);
                vecReserva[i].mostrar();
                rlutil::  locate (54,21);
                cout<<contador;
                rlutil::  locate (61,21);
                system("pause");
            }
        }
    }
    return contador;
}

int listarHistorialReservas(int dni)
{
    ReservasDAL regReserva;
    EmpleadoDAL regEmpleado;

    int legajo, contador=0;
    Fecha fechaHoy;

    int cantidad=regReserva.getCantidad();
    ReservaDTO* vecReserva= new ReservaDTO[cantidad];

    if (cantidad > 0)
    {
        legajo = regEmpleado.buscarLegajo(dni);
        regReserva.leerTodos(vecReserva, cantidad);
        for(int i=0; i<cantidad; i++)
        {
            if(vecReserva[i].getLegajo()==legajo)
            {
                contador++;
                system("cls");
                rectangulo (2, 2, 100, 20);
                mostrar_mensaje ("***   HISTORIAL DE RESERVAS   ***", 39, 4);
                mostrar_mensaje ("      ---------------------  ", 39, 5);
                mostrar_mensaje ("ESTAS SON TUS RESERVAS: ", 20, 9);
                vecReserva[i].mostrar();
                rlutil::  locate (54,21);
                cout<<contador;
                rlutil::  locate (61,21);
                system("pause");
            }
        }
    }
    return contador;
}
