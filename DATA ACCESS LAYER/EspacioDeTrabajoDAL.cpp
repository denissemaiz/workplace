#include "EspacioDeTrabajoDAL.h"
#include <cstdio>

const char * RUTA_ESPACIO="Espacio.data";


bool EspacioDeTrabajoDAL::agregar (EspacioDeTrabajoDTO dto)
{
    bool agregar = false;
    FILE *p;
    p = fopen(RUTA_ESPACIO,"ab");
    if (p!=NULL)
    {
        fwrite(&dto, sizeof (EspacioDeTrabajoDTO),1,p);
        fclose (p);
        agregar = true;
    }
    return agregar;
}

bool EspacioDeTrabajoDAL::modificar(EspacioDeTrabajoDTO dto)
{
    EspacioDeTrabajoDTO aux;
    bool modificar = false;
    FILE *p;
    p = fopen(RUTA_ESPACIO,"rb+");
    if (p!=NULL)
    {
        while(fread(&aux, sizeof (EspacioDeTrabajoDTO),1,p))
        {
            if(dto.getTipo()==aux.getTipo())
            {
                fseek(p,sizeof dto*(dto.getTipo()-1),SEEK_SET);
                fwrite(&dto, sizeof (EspacioDeTrabajoDTO),1,p);
                fclose (p);
                modificar = true;
            }
        }
    }
    return modificar;
}


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

