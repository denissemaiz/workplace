#ifndef EMPLEADODTO_H
#define EMPLEADODTO_H

#include "PersonaDTO.h"

class EmpleadoDTO : public PersonaDTO
{
private:
    int legajo;
    int tipoEmpleado;
    char *sector;
    bool estado;

public:

    // CONSTRUCTOR:
    EmpleadoDTO();

    // SET:
    void setLegajo(int legajo);
    void setTipoEmpleado(int tipoEmpleado);
    void setSector(char *sector);
    void setEstado(bool estado);

    // GET:
    int getLegajo();
    int getTipoEmpleado();
    char *getSector();
    bool getEstado();

    // METODOS:
    void Cargar();
};

#endif // EMPLEADODTO_H
