#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_USER.h"
#include "EmpleadoDAL.h"
#include "EmpleadoDTO.h"
#include "PersonaDAL.h"


int agregarEmpleado()
{
    EmpleadoDAL reg;
    EmpleadoDTO empleado;
    PersonaDAL obj;
    int dni;
    bool agrego;
    rlutil::  locate (20,8);
    cout<<"DNI: ";
    rlutil::  locate (25,8);
    cin>>dni;
    bool encontro = obj.existeDNI(dni);
    if (encontro) {
        rlutil::  locate (20,10);
        cout<<"EL DNI YA EXISTE!";
        return 0;
    }
    empleado.PersonaDTO::cargar(dni);
    rlutil::  locate (20,17);
    empleado.cargar();
    rlutil::  locate (20,18);
    agrego = reg.agregar(empleado);
    if (agrego){ return 1; }
    return 0;
}

