#ifndef INVITADODTO_H_INCLUDED
#define INVITADODTO_H_INCLUDED

#include "PersonaDTO.h"

class InvitadoDTO : public PersonaDTO
{
private:
    char *sector;
    bool estado;

public:

    // CONSTRUCTOR:
    InvitadoDTO();

    // SET:
    void Setsector(char *sector);
    void Setestado(bool estado);

    // GET:
    char *Getsector();
    bool Getestado();

    // METODOS:
    void Cargar();
};

#endif // INVITADODTO_H_INCLUDED
