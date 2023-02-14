#include <iostream>
#include <windows.h>

using namespace std;

#include "PersonaDTO.h"
#include "rlutil.h"

char vacio[50] {"vacio"};


PersonaDTO::PersonaDTO()
{
    _dni=0;
    strcpy(vacio,_nombre);
    strcpy(vacio,_apellido);
    strcpy(vacio,_email);
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


void PersonaDTO::cargar(int dni)
{
    rlutil::setColor(rlutil::YELLOW);
    if(dni!=0)
    {
        _dni=dni;
    }
    else
    {
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
    cout<<"TELEFONO: ";
    rlutil::  locate (31,12);
    cin>>_telefono;
}

void PersonaDTO::mostrar(int dni)
{
    rlutil::setColor(rlutil::YELLOW);
    if(dni==0)
    {
        rlutil::  locate (20,10);
        cout<<"DNI: "  <<_dni;
    }
    rlutil::  locate (20,11);
    cout<<"NOMBRE: "   <<_nombre;
    rlutil::  locate (20,12);
    cout<<"APELLIDO: " <<_apellido;
    rlutil::  locate (20,13);
    cout<<"EMAIL: "    <<_email;
    rlutil::  locate (20,14);
    cout<<"TELEFONO: " <<_telefono;
}
