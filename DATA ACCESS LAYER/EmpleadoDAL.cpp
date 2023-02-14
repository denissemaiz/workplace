#include "EmpleadoDAL.h"
#include "EspacioDeTrabajoDTO.h"

const char *RUTA_EMPLEADO = "Empleado.data";

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

bool EmpleadoDAL::existeDNI (int DNI)
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

/**/

EmpleadoDTO EmpleadoDAL::leer(int nroRegistro)
{
    EmpleadoDTO registro;
    FILE* pFile = fopen(RUTA_EMPLEADO, "rb");
    if (pFile != NULL)
    {
        fseek(pFile, nroRegistro * sizeof(EmpleadoDTO), SEEK_SET);
        fread(&registro, sizeof(EmpleadoDTO), 1, pFile);
        fclose(pFile);
    }
    return registro;
}

bool EmpleadoDAL::leerTodos(EmpleadoDTO registros[], int cantidad)
{
    bool ok = false;
    FILE* pFile = fopen(RUTA_EMPLEADO, "rb");
    if (pFile != NULL)
    {
        fread(registros, sizeof(EmpleadoDTO), cantidad, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}

bool EmpleadoDAL::agregar(EmpleadoDTO registro)
{
    bool ok = false;
    FILE* pFile = fopen(RUTA_EMPLEADO, "ab");
    if (pFile != NULL)
    {
        fwrite(&registro, sizeof(EmpleadoDTO), 1, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}

bool EmpleadoDAL::modificar(EmpleadoDTO registro, int nroRegistro)
{
    bool ok = false;
    FILE* pFile = fopen(RUTA_EMPLEADO, "rb+");
    if (pFile != NULL)
    {
        fseek(pFile, nroRegistro * sizeof(EmpleadoDTO), SEEK_SET);
        fwrite(&registro, sizeof(EmpleadoDTO), 1, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}

int EmpleadoDAL::getCantidad(){
  int cantidad = 0;
  FILE* pFile = fopen(RUTA_EMPLEADO, "rb");
  if (pFile != NULL)
  {
    fseek(pFile, 0, SEEK_END);
    cantidad = ftell(pFile) / sizeof(EmpleadoDTO);
    fclose(pFile);
  }
  return cantidad;
}

int EmpleadoDAL::buscar(int dni){
  int nroRegistro = -1;
  int cantidad = getCantidad();
  EmpleadoDTO registro;
  for (int i = 0; i < cantidad; i++)
  {
    registro = leer(i);
    if (registro.getDni() == dni)
    {
      nroRegistro = i;
      break;
    }
  }
  return nroRegistro;
}

