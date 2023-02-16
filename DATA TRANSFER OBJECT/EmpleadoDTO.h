#ifndef EMPLEADODTO_H
#define EMPLEADODTO_H

#include "PersonaDTO.h"
#include "FUNCIONES_FRONT.h"

class EmpleadoDTO : public PersonaDTO
{
private:
    int _legajo;
    int _sector;
    bool _estado;

public:
    EmpleadoDTO();

    void setLegajo(int legajo);
    void setTipo(int tipo);
    void setSector(int sector);
    void setEstado(bool estado);

    int getLegajo();
    int getTipo();
    int getSector();
    bool getEstado();

    void cargar(int dni=0);  //si el dni es 0, lo carga; sino ya viene el dato, no lo pide
    void mostrar(int dni=0);
};

#endif // EMPLEADODTO_H
