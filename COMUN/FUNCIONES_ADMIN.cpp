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
    bool agrego = false;
    rlutil::  locate (20,8);
    cout<<"DNI: ";
    rlutil::  locate (25,8);
    cin>>dni;
    bool encontro = obj.existeDNI(dni);
    if (encontro) {
        rlutil::  locate (20,10);
        cout<<"EL DNI YA EXISTE!";
        system("pause>null");
        return 0;
    }
    empleado.PersonaDTO::cargar(dni);
    empleado.cargar();
    if(empleado.getSector() != 0){
        agrego = reg.agregar(empleado);
    }
    if (agrego){ return -1; }
    return 0;
}

bool listarEmpleados()
{
    EmpleadoDAL reg;
    EmpleadoDTO obj;
    int leyo=false, pos=0;
    while(reg.leerDeDisco(pos)==1)
    {
        obj.mostrar();
        leyo=true;
        pos++;
        cout<<endl;
    }
    return leyo;
}
