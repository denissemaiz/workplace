#include "InvitadoDAL.h"

// METODOS:
bool InvitadoDAL::Existe (const char* R)
{
    bool existe = false;
    FILE *p;
    p = fopen(R,"rb");
    if (p!=NULL)
    {
        fclose (p);
        existe = true;
    }
    return existe;
}

bool InvitadoDAL::Agregar (InvitadoDTO dto)
{
    bool Agregar = false;
    FILE *p;
    p = fopen(RUTA_INVITADO,"ab");
    if (p!=NULL)
    {
        fwrite(&dto, sizeof (InvitadoDTO),1,p);
        fclose (p);
        Agregar = true;
    }
    return Agregar;
}

bool InvitadoDAL::Modificar(InvitadoDTO dto)
{
    InvitadoDTO aux;
    bool Modificar = false;
    FILE *p;
    p = fopen(RUTA_INVITADO,"rb+");
    if (p!=NULL)
    {
        while(fread(&aux, sizeof (InvitadoDTO),1,p))
        {
            if(dto.Getdni()==aux.Getdni())
            {
                fseek(p,sizeof dto*(dto.Getdni()-1),SEEK_SET);
                fwrite(&dto, sizeof (InvitadoDTO),1,p);
                fclose (p);
                Modificar = true;
            }
        }

    }
    return Modificar;
}

int InvitadoDAL::ObtenerTamanio()
{
    int Resultado=0;
    int CantBytes=0;
    FILE *p;
    p = fopen(RUTA_INVITADO,"rb");
    if (p!=NULL)
    {
        fseek(p,0,SEEK_END);
        CantBytes=ftell(p);
        Resultado=CantBytes/sizeof (InvitadoDTO);
        fclose(p);
    }
    return Resultado;
}

InvitadoDTO InvitadoDAL::BuscarRegistro(int a,int b)
{
    InvitadoDTO dto;
    FILE *p;
    p = fopen(RUTA_INVITADO,"rb");
    if (p!=NULL)
    {
        fseek(p,-1*sizeof (InvitadoDTO),b);
        fread(&dto,sizeof (InvitadoDTO),1,p);
        fclose (p);
    }
    return dto;
}

InvitadoDTO InvitadoDAL::ObtenerPorDNI (int DNI)
{
    bool encontro=false;
    InvitadoDTO dto;
    FILE *p;
    p = fopen(RUTA_INVITADO,"rb");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (InvitadoDTO),1,p))
        {
            if(dto.Getdni()==DNI)
            {
                encontro=true;
                break;
            }
        }
        if(!encontro)
        {
            dto.Setdni(-1);
        }
    }
    else
    {
        dto.Setdni(-1);
    }
    fclose (p);
    return dto;
}

bool InvitadoDAL::Eliminar(InvitadoDTO dto)
{
    InvitadoDTO aux;
    bool Eliminar = false;
    FILE *p;
    p = fopen(RUTA_INVITADO,"rb+");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (InvitadoDTO),1,p))
        {
            if(dto.Getdni()==aux.Getdni())
            {
                fseek(p,sizeof dto*(dto.Getdni()-1),SEEK_SET);
                fwrite(&dto, sizeof (InvitadoDTO),1,p);
                fclose (p);
                Eliminar = true;
            }
        }
    }
    return Eliminar;
}
