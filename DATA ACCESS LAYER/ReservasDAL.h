#ifndef RESERVASDAL_H
#define RESERVASDAL_H
#include "ReservaDTO.h"

class ReservasDAL
{
public:
    ReservaDTO leer(int nroRegistro);
    bool leerTodos(ReservaDTO registros[], int cantidad);
    bool agregar(ReservaDTO registro);
    bool modificar(ReservaDTO registro, int nroRegistro);
    int getCantidad();
    int buscar(int nroReserva);
};

#endif // RESERVASDAL_H
