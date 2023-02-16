#ifndef ESPACIODETRABAJODAL_H
#define ESPACIODETRABAJODAL_H

#include "EspacioDeTrabajoDTO.h"
#include <cstdio>

class EspacioDeTrabajoDAL
{
public:
    /*bool eliminar (EspacioDeTrabajoDTO);*/ /**/
    EspacioDeTrabajoDTO leer(int nroRegistro);
    bool leerTodos(EspacioDeTrabajoDTO registros[], int cantidad);
    bool agregar(EspacioDeTrabajoDTO registro);
    bool modificar(EspacioDeTrabajoDTO registro, int nroRegistro);
    int getCantidad();
    int buscar(int tipoEspacio);
};

#endif // ESPACIODETRABAJODTO_H
