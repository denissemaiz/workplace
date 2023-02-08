#include "EspacioDeTrabajoDTO.h"

EspacioDeTrabajoDTO::EspacioDeTrabajoDTO(){

 _tipo_espacio=-1;
 _cant_puestos=0;
 _disponibilidad=0;
 _estado=false;

}


void EspacioDeTrabajoDTO::setTipo(int tipoespacio)
{
_tipo_espacio=tipoespacio;

}

void EspacioDeTrabajoDTO::setCantPuestos(int cantidadpuestos)
{
_cant_puestos=cantidadpuestos;

}
void EspacioDeTrabajoDTO::setDisponibilidad(int disponibilidad)
{
_disponibilidad=disponibilidad;

}

void EspacioDeTrabajoDTO::setEstado(bool estado)
{
_estado=estado;

}

int EspacioDeTrabajoDTO::getTipo()
{
return _tipo_espacio;
}

int EspacioDeTrabajoDTO::getCantPuestos()
{
return _cant_puestos;
}

int EspacioDeTrabajoDTO::getDisponibilidad()
{
return _disponibilidad;
}

bool EspacioDeTrabajoDTO::getEstado()
{
return _estado;
}
