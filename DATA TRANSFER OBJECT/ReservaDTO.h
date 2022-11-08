#ifndef RESERVADTO_H
#define RESERVADTO_H
#include "Fecha.h"
#include "Hora.h"

class ReservaDTO
{
   private:
       int _numero_reserva;
       int _legajo;
       int _espacio_trabajo;
       Fecha _fecha;
       Hora _hora_ingreso;
       Hora _hora_egreso;
       bool _estado_turno;

   public:
    void Setnumeroreserva (int numero);
    void Setlegajo (int legajo);
    void Setespaciodetrabajo(int espaciodetrabajo);
    void Setfecha(Fecha fecha);
    void Sethora_ingreso(Hora horaingreso);
    void Sethora_egreso(Hora horaegreso);
    void Setestado_turno(bool estadoturno);


    int Getnumeroreserva();
    int Getlegajo();
    int Getespaciodetrabajo();
    Fecha Getfecha();
    Hora Gethora_ingreso();
    Hora Gethora_egreso();
    bool Getestado_turno();

    void turno();
    void cargar();
    void mostrar();

};

#endif // RESERVADTO_H
