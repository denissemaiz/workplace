#ifndef ESPACIODETRABAJODAL_H
#define ESPACIODETRABAJODAL_H
#include <cstdio>
#include "EspacioDeTrabajoDTO.h"


class EspacioDeTrabajoDAL
{
    public:
        void PorcentajeOcupacionDiaria();
        void CantidadReservasMensualesPorDepto();
        int cantidadEspacios();
        void LeerEspaciodeTrabajo(EspacioDeTrabajoDTO VecEspacio[], int cant);

        };

#endif // ESPACIODETRABAJODTO_H
