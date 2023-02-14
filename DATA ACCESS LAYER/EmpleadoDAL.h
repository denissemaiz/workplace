#ifndef EMPLEADODAL_H
#define EMPLEADODAL_H
#include <cstdio>
#include "../DATA TRANSFER OBJECT/EmpleadoDTO.h"

class EmpleadoDAL
{
public:
    bool existe(const char*);
    bool eliminar (EmpleadoDTO);
    EmpleadoDTO buscarRegistro(int,int);
    EmpleadoDTO obtenerPorDNI (int);
    bool existeDNI(int);

    /**/
    EmpleadoDTO leer(int nroRegistro);
    bool leerTodos(EmpleadoDTO registros[], int cantidad);
    bool agregar(EmpleadoDTO registro);
    bool modificar(EmpleadoDTO registro, int nroRegistro);
    int getCantidad();
    int buscar(int dni);
};

#endif // EMPLEADODAL_H
