#include "EmpleadoDAL.h"

// METODOS:
bool EmpleadoDAL::Existe (const char* R)
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

bool EmpleadoDAL::Agregar (EmpleadoDTO dto)
{
    bool Agregar = false;
    FILE *p;
    p = fopen(RUTA_EMPLEADO,"ab");
    if (p!=NULL)
    {
        fwrite(&dto, sizeof (EmpleadoDTO),1,p);
        fclose (p);
        Agregar = true;
    }
    return Agregar;
}

bool EmpleadoDAL::Modificar(EmpleadoDTO dto)
{
    EmpleadoDTO aux;
    bool Modificar = false;
    FILE *p;
    p = fopen(RUTA_EMPLEADO,"rb+");
    if (p!=NULL)
    {
        while(fread(&aux, sizeof (EmpleadoDTO),1,p))
        {
            if(dto.Getlegajo()==aux.Getlegajo())
            {
                fseek(p,sizeof dto*(dto.Getlegajo()-1),SEEK_SET);
                fwrite(&dto, sizeof (EmpleadoDTO),1,p);
                fclose (p);
                Modificar = true;
            }
        }

    }
    return Modificar;
}

int EmpleadoDAL::ObtenerTamanio()
{
    int Resultado=0;
    int CantBytes=0;
    FILE *p;
    p = fopen(RUTA_EMPLEADO,"rb");
    if (p!=NULL)
    {
        fseek(p,0,SEEK_END);
        CantBytes=ftell(p);
        Resultado=CantBytes/sizeof (EmpleadoDTO);
        fclose(p);
    }
    return Resultado;
}

EmpleadoDTO EmpleadoDAL::BuscarRegistro(int a,int b)
{
    EmpleadoDTO dto;
    FILE *p;
    p = fopen(RUTA_EMPLEADO,"rb");
    if (p!=NULL)
    {
        fseek(p,-1*sizeof (EmpleadoDTO),b);
        fread(&dto,sizeof (EmpleadoDTO),1,p);
        fclose (p);
    }
    return dto;
}

EmpleadoDTO EmpleadoDAL::ObtenerPorDNI (int DNI)
{
    bool encontro=false;
    EmpleadoDTO dto;
    FILE *p;
    p = fopen(RUTA_EMPLEADO,"rb");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (EmpleadoDTO),1,p))
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

bool EmpleadoDAL::Eliminar(EmpleadoDTO dto)
{
    EmpleadoDTO aux;
    bool Eliminar = false;
    FILE *p;
    p = fopen(RUTA_EMPLEADO,"rb+");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (EmpleadoDTO),1,p))
        {
            if(dto.Getdni()==aux.Getdni())
            {
                fseek(p,sizeof dto*(dto.Getlegajo()-1),SEEK_SET);
                fwrite(&dto, sizeof (EmpleadoDTO),1,p);
                fclose (p);
                Eliminar = true;
            }
        }
    }
    return Eliminar;
}
