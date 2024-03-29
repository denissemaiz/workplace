#include "EmpleadoDAL.h"
#include "EspacioDeTrabajoDTO.h"

const char *RUTA_EMPLEADO = "Empleado.data";

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

int EmpleadoDAL::getCantidad()
{
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

int EmpleadoDAL::buscar(int dni)
{
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

int EmpleadoDAL::buscarLegajo(int dni)
{
    int legajo = -1;
    int cantidad = getCantidad();
    EmpleadoDTO registro;
    for (int i = 0; i < cantidad; i++)
    {
        registro = leer(i);
        if (registro.getDni() == dni)
        {
            legajo = registro.getLegajo();
            break;
        }
    }
    return legajo;
}

int EmpleadoDAL::buscarPorLegajo(int legajo)
{
    int nroRegistro = -1;
    int cantidad = getCantidad();
    EmpleadoDTO registro;
    for (int i = 0; i < cantidad; i++)
    {
        registro = leer(i);
        if (registro.getLegajo() == legajo)
        {
            nroRegistro = registro.getLegajo();
            break;
        }
    }
    return nroRegistro;
}
