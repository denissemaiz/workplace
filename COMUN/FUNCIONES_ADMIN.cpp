#include "FUNCIONES_ADMIN.h"

#include "EmpleadoDAL.h"
#include "EmpleadoDTO.h"
#include "EspacioDeTrabajoDTO.h"
#include "EspacioDeTrabajoDAL.h"


///EMPLEADOS

int agregarEmpleado()
{
    EmpleadoDAL regEmpleado;
    EmpleadoDTO objEmpleado;
    int dni, nroRegistro;
    bool agrego = false;

    rlutil::  locate (20,8);
    cout<<"DNI: ";
    rlutil::  locate (25,8);
    cin>>dni;

    nroRegistro = regEmpleado.buscar(dni);

    if (nroRegistro!=-1)
    {
        rlutil::  locate (20,10);
        cout<<"EL DNI YA EXISTE!";
        system("pause>null");
        return 0;
    }
    objEmpleado.cargar(dni);
    if(objEmpleado.getSector() == 1 || 2 || 3 || 4)
    {
        agrego = regEmpleado.agregar(objEmpleado);
    }
    if (agrego == false)
    {
        return -1;
    }
    return 0;
}

bool modificarEmpleado()
{
    EmpleadoDAL regEmpleado;
    int dni, nroRegistro;
    bool modifico = false;

    int cantidad=regEmpleado.getCantidad();
    EmpleadoDTO* vecEmpleados= new EmpleadoDTO[cantidad];

    regEmpleado.leerTodos(vecEmpleados, cantidad);

    rlutil::  locate (20,8);
    cout<<"DNI: ";
    rlutil::  locate (25,8);
    cin>>dni;

    nroRegistro = regEmpleado.buscar(dni);

    if (nroRegistro==-1)
    {
        mostrar_mensaje ("* EL DNI INGRESADO NO EXISTE EN NUESTRA BASE DE DATOS *", 20, 10);
        system("pause>null");
    }
    else
    {
        vecEmpleados[nroRegistro].mostrar(dni);
        getch();
        modifico = menuModificarDatos(nroRegistro);
    }
    return modifico;
}

bool listarEmpleados()
{
    EmpleadoDAL regEmpleado;

    bool hayRegistros = false;
    int cantidad=regEmpleado.getCantidad();
    EmpleadoDTO* vecEmpleados= new EmpleadoDTO[cantidad];

    if (cantidad > 0)
    {
        regEmpleado.leerTodos(vecEmpleados, cantidad);
        for(int i=0; i<cantidad; i++)
        {
            if(vecEmpleados[i].getEstado()==true)
            {
                hayRegistros = true;
                system("cls");
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("LISTADO DE EMPLEADOS", 40, 5);
                mostrar_mensaje ("--------------------", 40, 6);
                vecEmpleados[i].mostrar();
                mostrar_mensaje ("ENTER PARA CONTINUAR..", 60, 25);
                getch();
            }
        }
    }
    return hayRegistros;
}


///ESPACIOS

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
