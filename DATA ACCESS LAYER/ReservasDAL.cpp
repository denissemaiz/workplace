#include "ReservasDAL.h"

const char *RUTA_RESERVA = "Reserva.data";

void ReservasDAL::reservasDiarias()
{

}

void ReservasDAL::reservasQuincenales()
{

}

void ReservasDAL::listadoPorDptoTrabajo()
{

}

void ReservasDAL::listadoOcupacionPorEmpleado()
{

}

/**/

ReservaDTO ReservasDAL::leer(int nroRegistro)
{
  ReservaDTO registro;
  FILE* pFile = fopen(RUTA_RESERVA, "rb");
  if (pFile != NULL)
  {
    fseek(pFile, nroRegistro * sizeof(ReservaDTO), SEEK_SET);
    fread(&registro, sizeof(ReservaDTO), 1, pFile);
    fclose(pFile);
  }
  return registro;
}

bool ReservasDAL::leerTodos(ReservaDTO registros[], int cantidad)
{
  bool ok = false;
  FILE* pFile = fopen(RUTA_RESERVA, "rb");
  if (pFile != NULL)
  {
    fread(registros, sizeof(ReservaDTO), cantidad, pFile);
    fclose(pFile);
    ok = true;
  }
  return ok;
}

bool ReservasDAL::guardar(ReservaDTO registro)
{
  bool ok = false;
  FILE* pFile = fopen(RUTA_RESERVA, "ab");
  if (pFile != NULL)
  {
    fwrite(&registro, sizeof(ReservaDTO), 1, pFile);
    fclose(pFile);
    ok = true;
  }
  return ok;
}

bool ReservasDAL::guardar(ReservaDTO registro, int nroRegistro)
{
  bool ok = false;
  FILE* pFile = fopen(RUTA_RESERVA, "rb+");
  if (pFile != NULL)
  {
    fseek(pFile, nroRegistro * sizeof(ReservaDTO), SEEK_SET);
    fwrite(&registro, sizeof(ReservaDTO), 1, pFile);
    fclose(pFile);
    ok = true;
  }
  return ok;
}

int ReservasDAL::getCantidad()
{
  int cantidad = 0;
  FILE* pFile = fopen(RUTA_RESERVA, "rb");
  if (pFile != NULL)
  {
    fseek(pFile, 0, SEEK_END);
    cantidad = ftell(pFile) / sizeof(ReservaDTO);
    fclose(pFile);
  }
  return cantidad;
}

int ReservasDAL::buscar(int nroReserva)
{
  int nroRegistro = -1;
  int cantidad = getCantidad();
  ReservaDTO registro;
  for (int i = 0; i < cantidad; i++)
  {
    registro = leer(i);
    if (registro.getNumero() == nroReserva)
    {
      nroRegistro = i;
      break;
    }
  }
  return nroRegistro;
}

