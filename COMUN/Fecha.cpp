#include "Fecha.h"

// CONSTRUCTOR:
Fecha::Fecha()
{
    dia=00;
    mes=00;
    anio=00;
}

// SET:

void Fecha::Setdia(int dia)
{
    this->dia = dia;
}
void Fecha::Setmes(int mes)
{
    this->mes = mes;
}
void Fecha::Setanio(int anio)
{
    this->anio = anio;
}


// GET:
int Fecha::Getdia()
{
    return dia;
}
int Fecha::Getmes()
{
    return mes;
}
int Fecha::Getanio()
{
    return anio;
}


