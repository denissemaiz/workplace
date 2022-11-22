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
    PersonaDTO();

    void setDni(int dni);
    void setNombre(char *nombre);
    void setApellido(char *apellido);
    void setEmail(char *email);
    void setDomicilio(char *domicilio);
    void setTelefono(int telefono);

    int getDni();
    char * getNombre();
    char * getApellido();

    char * getEmail();
    char * getDomicilio();
    int getTelefono();

    void cargar();
    void mostrar();
};

#endif // PERSONADTO_H

