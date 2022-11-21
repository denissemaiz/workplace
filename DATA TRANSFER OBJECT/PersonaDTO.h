#ifndef PERSONADTO_H
#define PERSONADTO_H
#include "cstring"

#include "Fecha.h"

class PersonaDTO
{
protected:
    int _dni;
    char _nombre[50];
    char _apellido[50];
    char _email[50];
    char _domicilio[50];
    int _telefono;

public:

    // CONSTRUCTOR:
    PersonaDTO();

    // SET:
    void Setdni(int dni);
    void Setnombre(char *nombre);
    void Setapellido(char *apellido);
    void Setemail(char *email);
    void Setdomicilio(char *domicilio);
    void Settelefono(int telefono);

    // GET:
    int Getdni();
    char * Getnombre();
    char * Getapellido();

    char * Getemail();
    char * Getdomicilio();
    int Gettelefono();

    // METODOS:
   // void Copy(PersonaDTO);
    void Cargar();
    void Mostrar();
};

#endif // PERSONADTO_H

