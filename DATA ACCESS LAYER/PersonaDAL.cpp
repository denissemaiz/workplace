#include "PersonaDAL.h"

// METODOS:
bool PersonaDAL::Existe (const char* R)
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

bool PersonaDAL::Agregar (PersonaDTO dto)
{
    bool Agregar = false;
    FILE *p;
    p = fopen(RUTA_PERSONA,"ab");
    if (p!=NULL)
    {
        fwrite(&dto, sizeof (PersonaDTO),1,p);
        fclose (p);
        Agregar = true;
    }
    return Agregar;
}

bool PersonaDAL::Modificar(PersonaDTO dto)
{
    PersonaDTO aux;
    bool Modificar = false;
    FILE *p;
    p = fopen(RUTA_PERSONA,"rb+");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (PersonaDTO),1,p))
        {
            if(dto.Getdni()==aux.Getdni())
            {
                fseek(p,sizeof dto*(-1),SEEK_CUR);
                fwrite(&dto, sizeof (PersonaDTO),1,p);
                fclose (p);
                Modificar = true;
            }
        }

    }
    return Modificar;
}

int PersonaDAL::ObtenerTamanio()
{
    int Resultado=0;
    int CantBytes=0;
    FILE *p;
    p = fopen(RUTA_PERSONA,"rb");
    if (p!=NULL)
    {
        fseek(p,0,SEEK_END);
        CantBytes=ftell(p);
        Resultado=CantBytes/sizeof (PersonaDTO);
        fclose(p);
    }
    return Resultado;
}

PersonaDTO PersonaDAL::BuscarRegistro(int a,int b)
{
    PersonaDTO dto;
    FILE *p;
    p = fopen(RUTA_PERSONA,"rb");
    if (p!=NULL)
    {
        fseek(p,-1*sizeof (PersonaDTO),b);
        fread(&dto,sizeof (PersonaDTO),1,p);
        fclose (p);
    }
    return dto;
}

PersonaDTO PersonaDAL::ObtenerPorDNI (int DNI)
{
    bool encontro=false;
    PersonaDTO dto;
    FILE *p;
    p = fopen(RUTA_PERSONA,"rb");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (PersonaDTO),1,p))
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

bool PersonaDAL::Eliminar(PersonaDTO dto)
{
    PersonaDTO aux;
    bool Eliminar = false;
    FILE *p;
    p = fopen(RUTA_PERSONA,"rb+");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (PersonaDTO),1,p))
        {
            if(dto.Getdni()==aux.Getdni())
            {
                fseek(p,sizeof dto*(-1),SEEK_CUR);
                fwrite(&dto, sizeof (PersonaDTO),1,p);
                fclose (p);
                Eliminar = true;
            }
        }
    }
    return Eliminar;
}

