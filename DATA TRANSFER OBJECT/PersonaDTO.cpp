#include <iostream>
#include <windows.h>
using namespace std;
#include "PersonaDTO.h"
#include "rlutil.h"
char vacio[50]{"vacio"};

// CONSTRUCTOR:
PersonaDTO::PersonaDTO()
{
    _dni=0;
    strcpy(vacio,_nombre);
    strcpy(vacio,_apellido);
    strcpy(vacio,_email);
    strcpy(vacio,_domicilio);
    _telefono=0;
}

// SET:
void PersonaDTO::Setdni(int val)
{
    _dni = val;
}
void PersonaDTO::Setnombre(char *nombre)
{
    strcpy(_nombre,nombre);
}
void PersonaDTO::Setapellido(char *apellido)
{
    strcpy(_apellido,apellido);
}


void PersonaDTO::Setemail(char *email)
{
    strcpy(_email,email);
}
void PersonaDTO::Setdomicilio(char *domicilio)
{
    strcpy(_domicilio,domicilio);
}
void PersonaDTO::Settelefono(int telefono)
{
    _telefono = telefono;
}

// GET:
int PersonaDTO::Getdni()
{
    return _dni;
}

char * PersonaDTO::Getnombre()
{
    return _nombre;
}

char * PersonaDTO::Getapellido()
{
    return _apellido;
}

char * PersonaDTO::Getemail()
{
    return _email;
}
char * PersonaDTO::Getdomicilio()
{
    return _domicilio;
}
int PersonaDTO::Gettelefono()
{
    return _telefono;
}

/*
// METODOS:
void PersonaDTO::Copy(PersonaDTO persona)
{
    dni=persona.dni;
    strcpy(nombre,persona.nombre);
    strcpy(apellido,persona.apellido);
    strcpy(email,persona.email);
    strcpy(domicilio,persona.domicilio);
    telefono=persona.telefono;
}*/

void PersonaDTO::Cargar(){
    rlutil::setColor(rlutil::YELLOW);
    rlutil::  locate (20,8);
    cout<<"DNI: ";
    rlutil::  locate (25,8);
    cin>>_dni;
      rlutil::  locate (20,9);
    cout<<"NOMBRE: ";
      rlutil::  locate (29,9);
    cin>>_nombre;
      rlutil::  locate (20,10);
    cout<<"APELLIDO: ";
      rlutil::  locate (29,10);
    cin>>_apellido;
      rlutil::  locate (20,11);
    cout<<"EMAIL: ";
      rlutil::  locate (28,11);
    cin>>_email;
      rlutil::  locate (20,12);
    cout<<"TELÉFONO: ";
      rlutil::  locate (30,12);
    cin>>_telefono;

 system("cls");
}

void PersonaDTO::Mostrar(){

cout<<"Dni"     <<_dni<<endl;
cout<<"Nombre"   <<_nombre<<endl;
cout<<"Apellido" <<_apellido<<endl;
cout<<"Email"    <<_email<<endl;
cout<<"Telefono" <<_telefono<<endl;

}
