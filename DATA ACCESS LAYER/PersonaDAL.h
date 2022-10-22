#ifndef PERSONADAL_H
#define PERSONADAL_H
#include <cstdio>
#include "../DATA TRANSFER OBJECT/PersonaDTO.h"

const char RUTA_PERSONA [] = "Persona.data";

class PersonaDAL
{
public:

    // METODOS:
    bool Existe(const char*);
    bool Agregar (PersonaDTO);
    bool Modificar (PersonaDTO);
    bool Eliminar (PersonaDTO);
    int ObtenerTamanio();
    PersonaDTO BuscarRegistro(int,int);
    PersonaDTO ObtenerPorDNI (int);
};

#endif // PERSONADAL_H
