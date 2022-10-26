#include "EspacioDeTrabajo.h"
//constructor

EspacioDeTrabajo::EspacioDeTrabajo(){


 _nombre="";
 _tipo_espacio="";
 _cantidaddepuestos=0;
 _capacidad=200;
 _estado_espacio=false;


}
//sets

void EspacioDeTrabajo::Setnombre(char *nombre)
{
_nombre=nombre;

}
void EspacioDeTrabajo::Settipodeespacio(int tipoespacio)
{
_tipo_espacio=tipoespacio;

}
void EspacioDeTrabajo::Setcantidadpuestos(int cantidadpuestos)
{
_cantidaddepuestos=cantidadpuestos;

}
void EspacioDeTrabajo::Setcapacidad(int capacidad)
{
_capacidad=capacidad;

}
void EspacioDeTrabajo::Setestadoespacio(bool estadoespacio)
{
_estado_espacio=estadoespacio;

}
//gets

const char* EspacioDeTrabajo::Getnombre (){

return _nombre;
}
int EspacioDeTrabajo::Gettipoespacio()
{
return _tipo_espacio;
}

int EspacioDeTrabajo::Getcantidadpuestos()
{
return _cantidaddepuestos;
}

int EspacioDeTrabajo::Getcapacidad()
{
return _capacidad;
}

bool EspacioDeTrabajo::Getestadoespacio()
{
return _estado_espacio:

}
