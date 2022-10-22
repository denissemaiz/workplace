#ifndef EMPLEADODAL_H
#define EMPLEADODAL_H
#include <cstdio>
#include "../DATA TRANSFER OBJECT/EmpleadoDTO.h"

const char RUTA_EMPLEADO [] = "Empleado.data";

class EmpleadoDAL
{
public:

    // METODOS:
    bool Existe(const char*);
    bool Agregar (EmpleadoDTO);
    bool Modificar (EmpleadoDTO);
    bool Eliminar (EmpleadoDTO);
    int ObtenerTamanio();
    EmpleadoDTO BuscarRegistro(int,int);
    EmpleadoDTO ObtenerPorDNI (int);
};

#endif // EMPLEADODAL_H
