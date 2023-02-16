#include "ReservaDTO.h"


void ReservaDTO::setNumero(int numero)
{
    _numero=numero;
}

void ReservaDTO::setLegajo(int legajo)
{
    _legajo=legajo;
}

void ReservaDTO::setEspacioTrabajo(int espaciodetrabajo)
{
    _espacio_trabajo=espaciodetrabajo;
}

void ReservaDTO::setFecha(Fecha fecha)
{
    _fecha=fecha;
}

void ReservaDTO::setEstado(bool estadoturno)
{
    _estado=estadoturno;
}

int ReservaDTO::getNumero()
{
    return _numero;
}

int ReservaDTO::getLegajo()
{
    return _legajo;
}

int ReservaDTO::getEspacioTrabajo()
{
    return _espacio_trabajo;
}

Fecha ReservaDTO::getFecha()
{
    return _fecha;
}

bool ReservaDTO::getEstado()
{
    return _estado;
}

void ReservaDTO::mostrar()
{
    if(_estado==true)
    {
        rlutil::  locate (20,10);
        cout<<"NRO. DE RESERVA: "  <<_numero;
        rlutil::  locate (20,11);
        cout<<"LEGAJO: "   <<_legajo;
        rlutil::  locate (20,12);
        cout<<"ESPACIO DE TRABAJO: ";
        rlutil::  locate (40,12);
        switch(_espacio_trabajo)
        {
        case 0:
            cout<<"DESK";
            break;
        case 1:
            cout<<"SALA DE REUNIONES";
            break;
        case 2:
            cout<<"ESTACIONAMIENTO";
            break;
        case 3:
            cout<<"COMEDOR";
            break;
        }
        rlutil::  locate (20,13);
        cout<<"FECHA: ";
        _fecha.Mostrar();
    }
}
