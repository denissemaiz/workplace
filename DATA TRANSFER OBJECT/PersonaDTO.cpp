#include <iostream>
#include <windows.h>

using namespace std;

#include "PersonaDTO.h"
#include "rlutil.h"

char vacio[50]{"vacio"};


PersonaDTO::PersonaDTO()
{
    _dni=0;
    strcpy(vacio,_nombre);
    strcpy(vacio,_apellido);
    strcpy(vacio,_email);
    strcpy(vacio,_domicilio);
    _telefono=0;
}


void PersonaDTO::setDni(int val)
{
    _dni = val;
}

void PersonaDTO::setNombre(char *nombre)
{
    strcpy(_nombre,nombre);
}

void PersonaDTO::setApellido(char *apellido)
{
    strcpy(_apellido,apellido);
}

void PersonaDTO::setEmail(char *email)
{
    strcpy(_email,email);
}

void PersonaDTO::setDomicilio(char *domicilio)
{
    strcpy(_domicilio,domicilio);
}

void PersonaDTO::setTelefono(int telefono)
{
    _telefono = telefono;
}


int PersonaDTO::getDni()
{
    return _dni;
}

char * PersonaDTO::getNombre()
{
    return _nombre;
}

char * PersonaDTO::getApellido()
{
    return _apellido;
}

char * PersonaDTO::getEmail()
{
    return _email;
}

char * PersonaDTO::getDomicilio()
{
    return _domicilio;
}

int PersonaDTO::getTelefono()
{
    return _telefono;
}

/*
void PersonaDTO::Copy(PersonaDTO persona)
{
    dni=persona.dni;
    strcpy(nombre,persona.nombre);
    strcpy(apellido,persona.apellido);
    strcpy(email,persona.email);
    strcpy(domicilio,persona.domicilio);
    telefono=persona.telefono;
}*/


void PersonaDTO::cargar(int dni=0)
{
    rlutil::setColor(rlutil::YELLOW);
    if(dni!=0)
    {
        _dni=dni;
    } else {
        /**/
        rlutil::  locate (20,8);
        cout<<"DNI: ";
        rlutil::  locate (25,8);
        cin>>_dni;
    }
      rlutil::  locate (20,9);
    cout<<"NOMBRE: ";
      rlutil::  locate (28,9);
    cin>>_nombre;
      rlutil::  locate (20,10);
    cout<<"APELLIDO: ";
      rlutil::  locate (30,10);
    cin>>_apellido;
      rlutil::  locate (20,11);
    cout<<"EMAIL: ";
      rlutil::  locate (27,11);
    cin>>_email;
      rlutil::  locate (20,12);
    cout<<"TELÉFONO: ";
      rlutil::  locate (31,12);
    cin>>_telefono;
}

void PersonaDTO::mostrar()
{
    cout<<"Dni"     <<_dni<<endl;
    cout<<"Nombre"   <<_nombre<<endl;
    cout<<"Apellido" <<_apellido<<endl;
    cout<<"Email"    <<_email<<endl;
    cout<<"Telefono" <<_telefono<<endl;
}
