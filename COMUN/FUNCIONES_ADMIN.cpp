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


int agregarEmpleado() ///cargar empleado
{
    EmpleadoDAL regEmpleado;
    EmpleadoDTO objEmpleado;
    int dni;
    bool agrego = false;
    rlutil::  locate (20,8);
    cout<<"DNI: ";
    rlutil::  locate (25,8);
    cin>>dni;
    bool encontro = regEmpleado.existeDNI(dni);
    if (encontro) {
        rlutil::  locate (20,10);
        cout<<"EL DNI YA EXISTE!";
        system("pause>null");
        return 0;
    }
    objEmpleado.cargar(dni);
    if(objEmpleado.getSector() != 0){
        agrego = regEmpleado.agregar(objEmpleado);
    }
    if (agrego){ return -1; }
    return 0;
}

bool listarEmpleados()
{
    EmpleadoDAL regEmpleado;
    EmpleadoDTO objEmpleado;
    //int pos=0;
    bool hayRegistros = false;
    int cantidad=regEmpleado.cantidadEmpleados();
    EmpleadoDTO* vecEmpleados= new EmpleadoDTO[cantidad];

    if (cantidad > 0) {
        hayRegistros = true;
        regEmpleado.leerEmpleados(vecEmpleados, cantidad);
        for( int i=0; i<cantidad; i++)
        {
            vecEmpleados[i].mostrar();
            rlutil::  locate (10,25);
            system("pause");
        }
    }
    return hayRegistros;
}
