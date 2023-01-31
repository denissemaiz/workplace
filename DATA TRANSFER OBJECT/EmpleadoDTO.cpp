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

void EmpleadoDTO::setSector(char *sector)
{
    strcpy(_sector,sector);
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

char *EmpleadoDTO::getSector()
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
    rlutil::  locate (38,14);
    cin>>_tipo_empleado;
    rlutil::  locate (20,15);
    ///SECTOR ESTÁ FALLANDO
    /*cout<<"SECTOR: ";
    rlutil::  locate (28,15);
    cin>>_sector;*/
}
