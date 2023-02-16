#include "EspacioDeTrabajoDAL.h"

const char *RUTA_ESPACIO = "Espacio.data";

EspacioDeTrabajoDTO EspacioDeTrabajoDAL::leer(int nroRegistro)
{
    EspacioDeTrabajoDTO registro;
    FILE* pFile = fopen(RUTA_ESPACIO, "rb");
    if (pFile != NULL)
    {
        fseek(pFile, nroRegistro * sizeof(EspacioDeTrabajoDTO), SEEK_SET);
        fread(&registro, sizeof(EspacioDeTrabajoDTO), 1, pFile);
        fclose(pFile);
    }
    return registro;
}

bool EspacioDeTrabajoDAL::leerTodos(EspacioDeTrabajoDTO registros[], int cantidad)
{
    bool ok = false;
    FILE* pFile = fopen(RUTA_ESPACIO, "rb");
    if (pFile != NULL)
    {
        fread(registros, sizeof(EspacioDeTrabajoDTO), cantidad, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}

bool EspacioDeTrabajoDAL::agregar(EspacioDeTrabajoDTO registro)
{
    bool ok = false;
    FILE* pFile = fopen(RUTA_ESPACIO, "ab");
    if (pFile != NULL)
    {
        fwrite(&registro, sizeof(EspacioDeTrabajoDTO), 1, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}

bool EspacioDeTrabajoDAL::modificar(EspacioDeTrabajoDTO registro, int nroRegistro)
{
    bool ok = false;
    FILE* pFile = fopen(RUTA_ESPACIO, "rb+");
    if (pFile != NULL)
    {
        fseek(pFile, nroRegistro * sizeof(EspacioDeTrabajoDTO), SEEK_SET);
        fwrite(&registro, sizeof(EspacioDeTrabajoDTO), 1, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}

int EspacioDeTrabajoDAL::getCantidad()
{
    int cantidad = 0;
    FILE* pFile = fopen(RUTA_ESPACIO, "rb");
    if (pFile != NULL)
    {
        fseek(pFile, 0, SEEK_END);
        cantidad = ftell(pFile) / sizeof(EspacioDeTrabajoDTO);
        fclose(pFile);
    }
    return cantidad;
}

int EspacioDeTrabajoDAL::buscar(int tipoEspacio)
{
    int nroRegistro = -1;
    int cantidad = getCantidad();
    EspacioDeTrabajoDTO registro;
    for (int i = 0; i < cantidad; i++)
    {
        registro = leer(i);
        if (registro.getTipo() == tipoEspacio)
        {
            nroRegistro = i;
            break;
        }
    }
    return nroRegistro;
}
