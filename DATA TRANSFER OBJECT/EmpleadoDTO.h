#ifndef EMPLEADODTO_H
#define EMPLEADODTO_H

#include "PersonaDTO.h"

class EmpleadoDTO : public PersonaDTO
{
private:
    int _legajo;
    int _tipoempleado;
    char *_sector;
    bool _estado;

public:

    // CONSTRUCTOR:
    EmpleadoDTO();

    // SET:
    void Setlegajo(int legajo);
    void Settipoempleado(int tipoempleado);
    void Setsector(char *sector);
    void Setestado(bool estado);

    // GET:
    int Getlegajo();
    int Gettipoempleado();
    char *Getsector();
    bool Getestado();

    // METODOS:
    void Cargar();
};

#endif // EMPLEADODTO_H
