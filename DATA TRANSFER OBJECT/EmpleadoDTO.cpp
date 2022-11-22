#include <iostream>
using namespace std;
#include "EmpleadoDTO.h"


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
    //PersonaDAL::Cargar();
    cout<<"LEGAJO: ";
    cin>>_legajo;
    /**/cout<<"TIPO DE EMPLEADO: ";
    cin>>_tipo_empleado;
    cout<<"SECTOR: ";
    cin>>_sector;
}
