#ifndef ESPACIODETRABAJODAL_H
#define ESPACIODETRABAJODAL_H
#include <cstdio>
#include "EspacioDeTrabajoDTO.h"


class EspacioDeTrabajoDAL
{
public:
    bool agregar (EspacioDeTrabajoDTO);
    bool modificar (EspacioDeTrabajoDTO);
    bool eliminar (EspacioDeTrabajoDTO);
    int cantidadEspacios();
    void LeerEspaciodeTrabajo(EspacioDeTrabajoDTO VecEspacio[], int cant);
    bool existeTipo(int tipo);
    //void PorcentajeOcupacionDiaria();
    //void CantidadReservasMensualesPorDepto();
};

#endif // ESPACIODETRABAJODTO_H
