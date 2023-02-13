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
#include "EspacioDeTrabajoDTO.h"
#include "EspacioDeTrabajoDAL.h"


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
    if (encontro)
    {
        rlutil::  locate (20,10);
        cout<<"EL DNI YA EXISTE!";
        system("pause>null");
        return 0;
    }
    objEmpleado.cargar(dni);
    if(objEmpleado.getSector() != 0)
    {
        agrego = regEmpleado.agregar(objEmpleado);
    }
    if (agrego)
    {
        return -1;
    }
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

    if (cantidad > 0)
    {
        hayRegistros = true;
        regEmpleado.leerEmpleados(vecEmpleados, cantidad);
        for( int i=0; i<cantidad; i++)
        {
            system("cls");
            rectangulo (2, 2, 100, 26);
            mostrar_mensaje ("LISTADO DE EMPLEADOS", 40, 5);
            mostrar_mensaje ("--------------------", 40, 6);
            vecEmpleados[i].mostrar();
            mostrar_mensaje ("ENTER PARA CONTINUAR..", 60, 25);
            getch();
        }
    }
    return hayRegistros;
}

bool definirEspacios(int espacio)
{
    EspacioDeTrabajoDTO objEspacio;
    EspacioDeTrabajoDAL regEspacio;
    int cant_puestos, nroRegistro;
    bool guardo = false;

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("INGRESE LA CANTIDAD DE PUESTOS DEL ESPACIO: ", 29, 8);
    rlutil::setColor(rlutil::YELLOW);
    rectangulo (45, 11, 4, 1);
    rlutil::  locate (46,12);
    cin>>cant_puestos;

    objEspacio.setTipo(espacio);
    objEspacio.setCantPuestos(cant_puestos);
    objEspacio.setDisponibilidad(cant_puestos);
    objEspacio.setEstado(true);

    nroRegistro = regEspacio.buscar(espacio);

    if (nroRegistro!=-1)   //el espacio ya existe -> lo modificamos
    {
        guardo = regEspacio.modificar(objEspacio, nroRegistro);
    }
    else     //el espacio no existe -> lo agregamos
    {
        guardo = regEspacio.agregar(objEspacio);
    }
    return guardo;
}

bool limitarEspacios(int espacio)
{
    EspacioDeTrabajoDTO objEspacio;
    EspacioDeTrabajoDAL regEspacio;
    int disponibilidad;

    int cantidad=regEspacio.getCantidad();
    EspacioDeTrabajoDTO* vecEspacios= new EspacioDeTrabajoDTO[cantidad];

    regEspacio.leerTodos(vecEspacios,cantidad);

    cout<<"Ingrese la disponibilidad del espacio";
    cin>>disponibilidad;

    vecEspacios[espacio].setDisponibilidad(disponibilidad);
    /*NO ESTAMOS MODIFICANDO EL ARCHIVO CON ESTE .SET; SOLO EL VECTOR*/
}

bool listarEspacios()
{
    EspacioDeTrabajoDAL regEspacio;

    bool hayRegistros = false;
    int cantidad=regEspacio.getCantidad();
    EspacioDeTrabajoDTO* vecEspacios= new EspacioDeTrabajoDTO[cantidad];

    if (cantidad > 0)
    {
        hayRegistros = true;
        regEspacio.leerTodos(vecEspacios, cantidad);
        for( int i=0; i<cantidad; i++)
        {
            rectangulo (2, 2, 100, 26);
            rlutil::setColor(rlutil::YELLOW);
            vecEspacios[i].mostrar();
            rlutil::  locate (10,25);
            system("pause");
            system("cls");
        }
    }
    return hayRegistros;
}
