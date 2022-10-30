#ifndef INVITADODAL_H_INCLUDED
#define INVITADODAL_H_INCLUDED
#include <cstdio>
#include "../DATA TRANSFER OBJECT/InvitadoDTO.h"

const char RUTA_INVITADO [] = "Invitado.data";

class InvitadoDAL
{
public:

    // METODOS:
    bool Existe(const char*);
    bool Agregar (InvitadoDTO);
    bool Modificar (InvitadoDTO);
    bool Eliminar (InvitadoDTO);
    int ObtenerTamanio();
    InvitadoDTO BuscarRegistro(int,int);
    InvitadoDTO ObtenerPorDNI (int);
};


#endif // INVITADODAL_H_INCLUDED
