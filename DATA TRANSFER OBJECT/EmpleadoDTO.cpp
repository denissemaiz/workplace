#include "EmpleadoDTO.h"

// CONSTRUCTOR:
EmpleadoDTO::EmpleadoDTO()
{
    //ctor
}

// SET:
void EmpleadoDTO::Setlegajo(int legajo)
{
    this->legajo = legajo;
}

void EmpleadoDTO::Settipoempleado(int tipoempleado)
{
    this->tipoempleado = tipoempleado;
}

void EmpleadoDTO::Setsector(char *sector)
{
    strcpy(this->sector,sector);
}

void EmpleadoDTO::Setestado(bool estao)
{
    this->estado = estado;
}

// GET:
int EmpleadoDTO::Getlegajo()
{
    return legajo;
}
int EmpleadoDTO::Gettipoempleado()
{
    return tipoempleado;
}
char *EmpleadoDTO::Getsector()
{
    return sector;
}
bool EmpleadoDTO::Getestado()
{
    return estado;
}
