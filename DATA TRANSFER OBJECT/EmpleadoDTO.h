#ifndef EMPLEADODTO_H
#define EMPLEADODTO_H

#include "PersonaDTO.h"

class EmpleadoDTO : public PersonaDTO
{
private:
    int _legajo;
    int _tipo_empleado;
    char *_sector;
    bool _estado;

public:
    EmpleadoDTO();

    void setLegajo(int legajo);
    void setTipo(int tipo);
    void setSector(char *sector);
    void setEstado(bool estado);

    int getLegajo();
    int getTipo();
    char *getSector();
    bool getEstado();

    void cargar();
};

#endif // EMPLEADODTO_H
