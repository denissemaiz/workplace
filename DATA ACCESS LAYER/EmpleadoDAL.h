#ifndef EMPLEADODAL_H
#define EMPLEADODAL_H

#include "EmpleadoDTO.h"

class EmpleadoDAL
{
public:
    bool eliminar (EmpleadoDTO);  /**/
    EmpleadoDTO leer(int nroRegistro);
    bool leerTodos(EmpleadoDTO registros[], int cantidad);
    bool agregar(EmpleadoDTO registro);
    bool modificar(EmpleadoDTO registro, int nroRegistro);
    int getCantidad();
    int buscar(int dni);
    int buscarLegajo(int dni);
};

#endif // EMPLEADODAL_H
