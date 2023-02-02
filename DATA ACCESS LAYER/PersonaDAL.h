#ifndef PERSONADAL_H
#define PERSONADAL_H
#include <cstdio>
#include "../DATA TRANSFER OBJECT/PersonaDTO.h"

const char RUTA_PERSONA [] = "Persona.data";

class PersonaDAL
{
public:
    void leerEmpleados(PersonaDTO empleado[], int cantidad);
    void cargarEmpleados(PersonaDTO empleado);
    void guardar(PersonaDTO empleado);
    int cantidadEmpleados();
    bool existe(const char*);
    bool agregar (PersonaDTO);
    bool modificar (PersonaDTO);
    bool eliminar (PersonaDTO);
    int obtenerTamanio();
    PersonaDTO buscarRegistro(int, int);
    PersonaDTO obtenerPorDNI (int);
    int leerDeDisco(int pos);
};

#endif // PERSONADAL_H
