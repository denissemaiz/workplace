#include "PersonaDAL.h"
using namespace std;

/*
void PersonaDAL::leerEmpleados(PersonaDTO empleados[], int cantidad)
{
    FILE* p;
    p= fopen(RUTA_PERSONA,"rb");

    if(p==nullptr)
    {
        return;
    }

    fread(empleados, sizeof(PersonaDTO),cantidad,p);
    fclose(p);
}


void PersonaDAL::guardar(PersonaDTO empleado)
{
    FILE* p;
    p = fopen(RUTA_PERSONA,"ab");

    if (p == nullptr)
    {
        cout<<"Error al abrir el archivo" <<endl;
        exit(1552);
    }
    else
    {
        fwrite(&empleado, sizeof(PersonaDTO), 1, p);
        fclose(p);
    }
}


int PersonaDAL::cantidadEmpleados()
{
    FILE *p;
    int cantidad=0;
    PersonaDTO empleado;
    p=fopen(RUTA_PERSONA,"rb");

    if (p==nullptr)
    {
        return 0;
    }

    fseek(p,0,SEEK_END);
    cantidad=ftell(p)/sizeof(PersonaDTO);
    fclose (p);

    return cantidad;
}


bool PersonaDAL::existe (const char* R)
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

bool PersonaDAL::agregar (PersonaDTO dto)
{
    bool agregar = false;
    FILE *p;
    p = fopen(RUTA_PERSONA,"ab");

    if (p!=NULL)
    {
        fwrite(&dto, sizeof (PersonaDTO),1,p);
        fclose (p);
        agregar = true;
    }
    return agregar;
}

bool PersonaDAL::modificar(PersonaDTO dto)
{
    PersonaDTO aux;
    bool modificar = false;
    FILE *p;
    p = fopen(RUTA_PERSONA,"rb+");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (PersonaDTO),1,p))
        {
            if(dto.getDni()==aux.getDni())
            {
                fseek(p,sizeof dto*(-1),SEEK_CUR);
                fwrite(&dto, sizeof (PersonaDTO),1,p);
                fclose (p);
                modificar = true;
            }
        }
    }
    return modificar;
}

int PersonaDAL::obtenerTamanio()
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

PersonaDTO PersonaDAL::buscarRegistro(int a,int b)
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

PersonaDTO PersonaDAL::obtenerPorDNI (int DNI)
{
    bool encontro=false;
    PersonaDTO dto;
    FILE *p;
    p = fopen(RUTA_PERSONA,"rb");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (PersonaDTO),1,p))
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


int PersonaDAL::leerDeDisco(int pos)
{
    FILE *p;
    int leyo=0;
    p=fopen(RUTA_PERSONA, "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(PersonaDAL)*pos, 0);
    leyo=fread(this, sizeof(PersonaDAL),1, p);
    fclose(p);
    return leyo;
}

bool PersonaDAL::eliminar(PersonaDTO dto)
{
    PersonaDTO aux;
    bool eliminar = false;
    FILE *p;
    p = fopen(RUTA_PERSONA,"rb+");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (PersonaDTO),1,p))
        {
            if(dto.getDni()==aux.getDni())
            {
                fseek(p,sizeof dto*(-1),SEEK_CUR);
                fwrite(&dto, sizeof (PersonaDTO),1,p);
                fclose (p);
                eliminar = true;
            }
        }
    }
    return eliminar;
}

*/
