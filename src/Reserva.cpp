#include "Reserva.h"
//sets

void Reserva::Setnumeroreserva(int numero){

_numero_reserva=numero;

}
void Reserva::Setlegajo(int legajo){

_legajo=legajo;
}

void Reserva::Setespaciodetrabajo(int espaciodetrabajo){

_espacio_trabajo=espaciodetrabajo;

}

void Reserva::Setfecha(Fecha fecha){

_fecha=fecha;

}
void Reserva::Sethora_ingreso(Hora horaingreso){


_hora_ingreso=horaingreso;

}
void Reserva::Sethora_egreso(Hora horaegreso){

_hora_egreso=horaegreso;
}

void Reserva::Setestado_turno(bool estadoturno){

_estado_turno=estadoturno;

}

//gets

int Reserva::Getnumeroreserva(){

return _numero_reserva;

}
int Reserva::Getlegajo(){

return _legajo;

}

int Reserva::Getespaciodetrabajo(){

return _espacio_trabajo;

}
Fecha Reserva::Getfecha(){

return _fecha;

}
Hora Reserva::Gethora_ingreso(){

return _hora_ingreso;

}
Hora Reserva::Gethora_egreso(){

return _hora_ingreso;

}
bool Reserva::Getestado_turno(){

return _estado_turno;
}

void Reserva::turno(){





}
