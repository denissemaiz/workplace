#ifndef EMPLEADODAL_H
#define EMPLEADODAL_H
#include <cstdio>
#include "../DATA TRANSFER OBJECT/EmpleadoDTO.h"

const char RUTA_EMPLEADO [] = "Empleado.data";

class EmpleadoDAL
{
public:
    // METODOS:
    bool existe(const char*);
    bool agregar (EmpleadoDTO);
    bool modificar (EmpleadoDTO);
    bool eliminar (EmpleadoDTO);
    int obtenerTamanio();
    EmpleadoDTO buscarRegistro(int,int);
    EmpleadoDTO obtenerPorDNI (int);
    int leerDeDisco(int pos);
};

#endif // EMPLEADODAL_H
