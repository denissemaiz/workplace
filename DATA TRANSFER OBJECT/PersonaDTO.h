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
    /**/Fecha fechanacimiento;
    char email[50];
    char domicilio[50];
    int telefono;

public:

    // CONSTRUCTOR:
    PersonaDTO();

    // SET:
    void Setdni(int dni);
    void Setnombre(char *nombre);
    void Setapellido(char *apellido);
    /**/void Setfechanacimiento(Fecha fechanacimiento) { this->fechanacimiento = fechanacimiento; }
    void Setemail(char *email);
    void Setdomicilio(char *domicilio);
    void Settelefono(int telefono);

    // GET:
    int Getdni();
    char * Getnombre();
    char * Getapellido();
    /**/Fecha Getfechanacimiento() { return fechanacimiento; }
    char * Getemail();
    char * Getdomicilio();
    int Gettelefono();

    // METODOS:
    void Copy(PersonaDTO);
    void Cargar();
};

#endif // PERSONADTO_H

