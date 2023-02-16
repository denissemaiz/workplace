#ifndef RESERVADTO_H
#define RESERVADTO_H
#include "Fecha.h"
#include "Hora.h"

class ReservaDTO
{
   private:
       int _numero;
       int _legajo;
       int _espacio_trabajo;
       Fecha _fecha;
       bool _estado;

   public:
    void setNumero (int numero);
    void setLegajo (int legajo);
    void setEspacioTrabajo(int espaciotrabajo);
    void setFecha(Fecha fecha);
    void setEstado(bool estado);

    int getNumero();
    int getLegajo();
    int getEspacioTrabajo();
    Fecha getFecha();
    bool getEstado();

    void cargar();
    void mostrar();
};

#endif // RESERVADTO_H
