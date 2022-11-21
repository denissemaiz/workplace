#include <iostream>
using namespace std;
#include "EmpleadoDTO.h"

// CONSTRUCTOR:
EmpleadoDTO::EmpleadoDTO()
{
    //ctor
}

// SET:
void EmpleadoDTO::Setlegajo(int legajo)
{
    _legajo = legajo;
}

void EmpleadoDTO::Settipoempleado(int tipoempleado)
{
    _tipoempleado = tipoempleado;
}

void EmpleadoDTO::Setsector(char *sector)
{
    strcpy(_sector,sector);
}

void EmpleadoDTO::Setestado(bool estado)
{
    _estado = estado;
}

// GET:
int EmpleadoDTO::Getlegajo()
{
    return _legajo;
}
int EmpleadoDTO::Gettipoempleado()
{
    return _tipoempleado;
}
char *EmpleadoDTO::Getsector()
{
    return _sector;
}
bool EmpleadoDTO::Getestado()
{
    return _estado;
}

void EmpleadoDTO::Cargar(){
    //PersonaDAL::Cargar();;
    cout<<"LEGAJO: ";
    cin>>_legajo;
    /**/cout<<"TIPO DE EMPLEADO: ";
    cin>>_tipoempleado;
    cout<<"SECTOR: ";
    cin>>_sector;
}
