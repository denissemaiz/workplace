#include <iostream>

using namespace std;

#include "EspacioDeTrabajoDTO.h"
#include "FUNCIONES_FRONT.h"
#include "rlutil.h"

EspacioDeTrabajoDTO::EspacioDeTrabajoDTO()
{
    _tipo_espacio=-1;
    _cant_puestos=0;
    _estado=false;
}

void EspacioDeTrabajoDTO::setTipo(int tipoespacio)
{
    _tipo_espacio=tipoespacio;

}

void EspacioDeTrabajoDTO::setCantPuestos(int cantidadpuestos)
{
    _cant_puestos=cantidadpuestos;

}

void EspacioDeTrabajoDTO::setEstado(bool estado)
{
    _estado=estado;

}

int EspacioDeTrabajoDTO::getTipo()
{
    return _tipo_espacio;
}

int EspacioDeTrabajoDTO::getCantPuestos()
{
    return _cant_puestos;
}

bool EspacioDeTrabajoDTO::getEstado()
{
    return _estado;
}

void EspacioDeTrabajoDTO::mostrar()
{
    if(_estado==true)
    {
        rlutil::  locate (20,13);
        cout<<"TIPO DE ESPACIO: ";
        rlutil::  locate (37,13);
        switch(_tipo_espacio)
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
        rlutil::  locate (20,14);
        cout<<"CANTIDAD DE PUESTOS: ";
        rlutil::  locate (41,14);
        cout<<_cant_puestos;
        rlutil::  locate (20,15);
        cout<<"DISPONIBILIDAD: ";
        rlutil::  locate (36,15);
        cout<<_cant_puestos;
    }
}
