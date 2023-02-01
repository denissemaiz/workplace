#include <iostream>
using namespace std;
#include "EmpleadoDTO.h"
#include "FUNCIONES_FRONT.h"
#include "rlutil.h"


EmpleadoDTO::EmpleadoDTO()
{
    //ctor
}


void EmpleadoDTO::setLegajo(int legajo)
{
    _legajo = legajo;
}

void EmpleadoDTO::setTipo(int tipoempleado)
{
    _tipo_empleado = tipoempleado;
}

void EmpleadoDTO::setSector(int sector)
{
    _sector = sector;
}

void EmpleadoDTO::setEstado(bool estado)
{
    _estado = estado;
}


int EmpleadoDTO::getLegajo()
{
    return _legajo;
}

int EmpleadoDTO::getTipo()
{
    return _tipo_empleado;
}

int EmpleadoDTO::getSector()
{
    return _sector;
}

bool EmpleadoDTO::getEstado()
{
    return _estado;
}


void EmpleadoDTO::cargar(){
    rlutil::  locate (20,13);
    cout<<"LEGAJO: ";
    rlutil::  locate (28,13);
    cin>>_legajo;
    rlutil::  locate (20,14);
    /**/cout<<"TIPO DE EMPLEADO: ";
    rlutil::  locate (20,15);
    cout<<"1-";
    rlutil::  locate (20,16);
    cout<<"2-";
    rlutil::  locate (20,17);
    cout<<"3-";
    rlutil::  locate (38,18);
    cin>>_tipo_empleado;
    rlutil::  locate (20,19);
    cout<<"SECTOR: ";
    rlutil::  locate (28,20);
    cin>>_sector;
}
