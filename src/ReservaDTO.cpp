#include "ReservaDTO.h"
//sets

void ReservaDTO::Setnumeroreserva(int numero){

_numero_reserva=numero;

}
void ReservaDTO::Setlegajo(int legajo){

_legajo=legajo;
}

void ReservaDTO::Setespaciodetrabajo(int espaciodetrabajo){

_espacio_trabajo=espaciodetrabajo;

}

void ReservaDTO::Setfecha(Fecha fecha){

_fecha=fecha;

}
void ReservaDTO::Sethora_ingreso(Hora horaingreso){


_hora_ingreso=horaingreso;

}
void ReservaDTO::Sethora_egreso(Hora horaegreso){

_hora_egreso=horaegreso;
}

void ReservaDTO::Setestado_turno(bool estadoturno){

_estado_turno=estadoturno;

}

//gets

int ReservaDTO::Getnumeroreserva(){

return _numero_reserva;

}
int ReservaDTO::Getlegajo(){

return _legajo;

}

int ReservaDTO::Getespaciodetrabajo(){

return _espacio_trabajo;

}
Fecha ReservaDTO::Getfecha(){

return _fecha;

}
Hora ReservaDTO::Gethora_ingreso(){

return _hora_ingreso;

}
Hora ReservaDTO::Gethora_egreso(){

return _hora_ingreso;

}
bool ReservaDTO::Getestado_turno(){

return _estado_turno;
}

void ReservaDTO::turno(){





}
