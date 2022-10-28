#include <iostream>
using namespace std;
#include "EmpleadoDTO.h"

// CONSTRUCTOR:
EmpleadoDTO::EmpleadoDTO()
{
    //ctor
}

// SET:
void EmpleadoDTO::setLegajo(int legajo)
{
    this->legajo = legajo;
}

void EmpleadoDTO::setTipoEmpleado(int tipoEmpleado)
{
    this->tipoEmpleado = tipoEmpleado;
}

void EmpleadoDTO::setSector(char *sector)
{
    strcpy(this->sector,sector);
}

void EmpleadoDTO::setEstado(bool estao)
{
    this->estado = estado;
}

// GET:
int EmpleadoDTO::getLegajo()
{
    return legajo;
}
int EmpleadoDTO::getTipoEmpleado()
{
    return tipoEmpleado;
}
char *EmpleadoDTO::getSector()
{
    return sector;
}
bool EmpleadoDTO::getEstado()
{
    return estado;
}

void EmpleadoDTO::Cargar(){
    //PersonaDAL::Cargar();;
    cout<<"LEGAJO: ";
    cin>>legajo;
    /**/cout<<"TIPO DE EMPLEADO: ";
    cin>>tipoEmpleado;
    cout<<"SECTOR: ";
    cin>>sector;
}
