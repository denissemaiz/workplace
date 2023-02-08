#include <iostream>
using namespace std;
#include "EmpleadoDTO.h"
#include "FUNCIONES_FRONT.h"
#include "rlutil.h"


EmpleadoDTO::EmpleadoDTO()
{
    _legajo=0;
    _sector=0;
}


void EmpleadoDTO::setLegajo(int legajo)
{
    _legajo = legajo;
}


void EmpleadoDTO::setSector(int sector)
{
    _sector = sector;
}

void EmpleadoDTO::setEstado(bool estado)
{
    _estado = estado;
}


int EmpleadoDTO::getLegajo()
{
    return _legajo;
}


int EmpleadoDTO::getSector()
{
    return _sector;
}

bool EmpleadoDTO::getEstado()
{
    return _estado;
}


void EmpleadoDTO::cargar(int dni){
    _estado=true;
    PersonaDTO::cargar(dni);
    rlutil::  locate (20,13);
    cout<<"LEGAJO: ";
    rlutil::  locate (28,13);
    cin>>_legajo;
    rlutil::  locate (20,14);
    cout<<"SECTOR: ";
    rlutil::  locate (21,16);
    cout<<"1- ADMINISTRACION Y RRHH";
    rlutil::  locate (21,17);
    cout<<"2- MARKETING Y VENTAS";
    rlutil::  locate (21,18);
    cout<<"3- PRODUCCION Y SISTEMAS";
    rlutil::  locate (21,19);
    cout<<"4- CONTABILIDAD Y FINANZAS";
    rlutil::  locate (21,20);
    cout<<"5- DIRECCION";
    rlutil::  locate (28,14);
    cin>>_sector;
    if(_sector>5 || _sector<1){
        return;
    }
}

void EmpleadoDTO::mostrar()
{
    if(_estado==true)
    {
        PersonaDTO::mostrar();
        rlutil::  locate (20,13);
        cout<<"LEGAJO: ";
        rlutil::  locate (28,13);
        cout<<_legajo;
        /**/
        rlutil::  locate (20,14);
        cout<<"SECTOR: ";
        rlutil::  locate (28,14);
        switch(_sector)
        {
        case 1:
            cout<<"ADMINISTRACION Y RRHH";
            break;
        case 2:
            cout<<"MARKETING Y VENTAS";
            break;
        case 3:
            cout<<"PRODUCCION Y SISTEMAS";
            break;
        case 4:
            cout<<"CONTABILIDAD Y FINANZAS";
            break;
        case 5:
            cout<<"DIRECCION";
            break;
        }
    }
}
