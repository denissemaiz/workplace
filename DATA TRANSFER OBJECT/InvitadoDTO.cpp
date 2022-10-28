# include<iostream>
# include<cstdlib>
# include <cstring>

using namespace std;

#include "InvitadoDTO.h"

// CONSTRUCTOR:
InvitadoDTO::InvitadoDTO()
{
    //ctor
}

// SET:

void InvitadoDTO::Setsector(char *sector)
{
    strcpy(this->sector,sector);
}

void InvitadoDTO::Setestado(bool estao)
{
    this->estado = estado;
}

// GET:

char *InvitadoDTO::Getsector()
{
    return sector;
}
bool InvitadoDTO::Getestado()
{
    return estado;
}

void InvitadoDTO::Cargar(){
    //PersonaDAL::Cargar();;
    cout<<"SECTOR: ";
    cin>>sector;
}

