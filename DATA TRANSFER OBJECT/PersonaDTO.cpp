#include <iostream>
#include <windows.h>
using namespace std;
#include "PersonaDTO.h"

char vacio[50]{"vacio"};

// CONSTRUCTOR:
PersonaDTO::PersonaDTO()
{
    dni=0;
    strcpy(vacio,nombre);
    strcpy(vacio,apellido);
    strcpy(vacio,email);
    strcpy(vacio,domicilio);
    telefono=0;
}

// SET:
void PersonaDTO::Setdni(int val)
{
    dni = val;
}
void PersonaDTO::Setnombre(char *nombre)
{
    strcpy(this->nombre,nombre);
}
void PersonaDTO::Setapellido(char *apellido)
{
    strcpy(this->apellido,apellido);
}

//void Setfechanacimiento(Fecha fechanacimiento) { this->fechanacimiento = fechanacimiento; }

void PersonaDTO::Setemail(char *email)
{
    strcpy(this->email,email);
}
void PersonaDTO::Setdomicilio(char *domicilio)
{
    strcpy(this->domicilio,domicilio);
}
void PersonaDTO::Settelefono(int telefono)
{
    this->telefono = telefono;
}

// GET:
int PersonaDTO::Getdni()
{
    return dni;
}

char * PersonaDTO::Getnombre()
{
    return nombre;
}

char * PersonaDTO::Getapellido()
{
    return apellido;
}

//Fecha Getfechanacimiento() { return fechanacimiento; }
char * PersonaDTO::Getemail()
{
    return email;
}
char * PersonaDTO::Getdomicilio()
{
    return domicilio;
}
int PersonaDTO::Gettelefono()
{
    return telefono;
}

// METODOS:
void PersonaDTO::Copy(PersonaDTO persona)
{
    this->dni=persona.dni;
    strcpy(this->nombre,persona.nombre);
    strcpy(this->apellido,persona.apellido);
    //this->fechanacimiento=persona.fechanacimiento;
    strcpy(this->email,persona.email);
    strcpy(this->domicilio,persona.domicilio);
    this->telefono=persona.telefono;
}

void PersonaDTO::Cargar(){
    cout<<"DNI: ";
    cin>>dni;
    cout<<"NOMBRE: ";
    cin>>nombre;
    cout<<"APELLIDO: ";
    cin>>apellido;
    cout<<"FECHA DE NACIMIENTO: "<<std::endl;
    Sleep(500);
    //fechanacimiento.Cargar();
    cout<<"EMAIL: ";
    cin>>email;
    cout<<"TELÉFONO: ";
    cin>>telefono;
}
