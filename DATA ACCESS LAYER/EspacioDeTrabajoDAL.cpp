#include "EspacioDeTrabajoDAL.h"
#include <cstdio>

 const char * RUTA_ESPACIO="Espacio.data";


void EspacioDeTrabajoDAL::LeerEspaciodeTrabajo(EspacioDeTrabajoDTO VecEspacio[], int cant)
{

    FILE* p;
    p= fopen(RUTA_ESPACIO,"rb");

    if(p==nullptr)
    {
        return;
    }

    fread(VecEspacio, sizeof(EspacioDeTrabajoDTO),cant,p);
    fclose(p);
}

int EspacioDeTrabajoDAL::cantidadEspacios()
{
    FILE *p;
    int cantidad=0;
    EspacioDeTrabajoDTO espacio;
    p=fopen(RUTA_ESPACIO,"rb");

    if (p==nullptr)
    {
        return 0;
    }
    fseek(p,0,SEEK_END);
    cantidad=ftell(p)/sizeof(EspacioDeTrabajoDTO);
    fclose (p);

    return cantidad;
}

