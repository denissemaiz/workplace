#ifndef PERSONADTO_H
#define PERSONADTO_H
#include "cstring"

#include "Fecha.h"

class PersonaDTO
{
protected:
    int dni;
    char nombre[50];
    char apellido[50];
    /**/Fecha fechaNacimiento;
    char email[50];
    char domicilio[50];
    int telefono;

public:

    // CONSTRUCTOR:
    PersonaDTO();

    // SET:
    void setDni(int dni);
    void setNombre(char *nombre);
    void setapellido(char *apellido);
    /**/void setfechaNacimiento(Fecha fechaNacimiento) { this->fechaNacimiento = fechaNacimiento; }
    void setemail(char *email);
    void setdomicilio(char *domicilio);
    void settelefono(int telefono);

    // GET:
    int Getdni();
    char * Getnombre();
    char * Getapellido();
    /**/Fecha Getfechanacimiento() { return fechaNacimiento; }
    char * Getemail();
    char * Getdomicilio();
    int Gettelefono();

    // METODOS:
    void Copy(PersonaDTO);
    void Cargar();
};

#endif // PERSONADTO_H
