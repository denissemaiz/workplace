#include "EmpleadoDAL.h"

// METODOS:
bool EmpleadoDAL::existe (const char* R)
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

bool EmpleadoDAL::agregar (EmpleadoDTO dto)
{
    bool agregar = false;
    FILE *p;
    p = fopen(RUTA_EMPLEADO,"ab");
    if (p!=NULL)
    {
        fwrite(&dto, sizeof (EmpleadoDTO),1,p);
        fclose (p);
        agregar = true;
    }
    return agregar;
}

bool EmpleadoDAL::modificar(EmpleadoDTO dto)
{
    EmpleadoDTO aux;
    bool modificar = false;
    FILE *p;
    p = fopen(RUTA_EMPLEADO,"rb+");
    if (p!=NULL)
    {
        while(fread(&aux, sizeof (EmpleadoDTO),1,p))
        {
            if(dto.getLegajo()==aux.getLegajo())
            {
                fseek(p,sizeof dto*(dto.getLegajo()-1),SEEK_SET);
                fwrite(&dto, sizeof (EmpleadoDTO),1,p);
                fclose (p);
                modificar = true;
            }
        }
    }
    return modificar;
}

int EmpleadoDAL::obtenerTamanio()
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

EmpleadoDTO EmpleadoDAL::buscarRegistro(int a,int b) /*?*/
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

EmpleadoDTO EmpleadoDAL::obtenerPorDNI (int DNI)
{
    bool encontro=false;
    EmpleadoDTO dto;
    FILE *p;
    p = fopen(RUTA_EMPLEADO,"rb");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (EmpleadoDTO),1,p))
        {
            if(dto.getDni()==DNI)
            {
                encontro=true;
                break;
            }
        }
        if(!encontro)
        {
            dto.setDni(-1);
        }
    }
    else
    {
        dto.setDni(-1);
    }
    fclose (p);
    return dto;
}

bool EmpleadoDAL::eliminar(EmpleadoDTO dto)
{
    EmpleadoDTO aux;
    bool eliminar = false;
    FILE *p;
    p = fopen(RUTA_EMPLEADO,"rb+");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (EmpleadoDTO),1,p))
        {
            if(dto.getDni()==aux.getDni())
            {
                fseek(p,sizeof dto*(dto.getLegajo()-1),SEEK_SET);
                fwrite(&dto, sizeof (EmpleadoDTO),1,p);
                fclose (p);
                eliminar = true;
            }
        }
    }
    return eliminar;
}

int EmpleadoDAL::leerDeDisco(int pos)
{
    FILE *p;
    int leyo=0;
    p=fopen(RUTA_EMPLEADO, "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(EmpleadoDAL)*pos, 0);
    leyo=fread(this, sizeof(EmpleadoDAL),1, p);
    fclose(p);
    return leyo;
}

bool EmpleadoDAL::existeDNI (int DNI)
{
    bool encontro=false;
    PersonaDTO dto;
    FILE *p;
    p = fopen(RUTA_EMPLEADO,"rb");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (PersonaDTO),1,p))
        {
            if(dto.getDni()==DNI)
            {
                encontro=true;
            }
        }
        if(!encontro)
        {
            encontro=false;
        }
    }
    fclose (p);
    return encontro;
}



