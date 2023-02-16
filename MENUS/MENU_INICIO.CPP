#include "MENUS.h"
#include "FUNCIONES_FRONT.h"
#include "EmpleadoDAL.h"

void menuIncio()
{
    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 20);

    mostrar_mensaje ("___________________________", 40, 3);
    mostrar_mensaje ("* BIENVENIDO A WORKPLACE *",40, 5);
    mostrar_mensaje ("___________________________", 40, 6);

    EmpleadoDAL reg;
    int dni, nroRegistro;

    rlutil::  locate (36,12);
    cout <<"INGRESE SU DNI: ";
    rectangulo (51, 11, 10, 1);
    rlutil::  locate (53,12);
    cin >>dni;

    nroRegistro = reg.buscar(dni);

    if (dni == 1234)  ///PONGO UN NUMERO QUE EQUIVALGA A ADMINISTRADOR
    {
        system("cls");
        menuAdmin();
    }
    else if (nroRegistro != -1)
    {
        system("cls");
        menuUser(dni);
    }
    else if (validarDni(dni))
    {
        mostrar_mensaje ("EL DNI INGRESADO NO EXISTE EN NUESTRA BASE DE DATOS.", 28, 16);
        rlutil::  locate (60,21);
        system("pause");
        system("cls");
        menuIncio();
    }
    else
    {
        mostrar_mensaje ("EL DNI INGRESADO NO ES VALIDO.", 35, 17);
        rlutil::  locate (60,21);
        system("pause");
        system("cls");
        menuIncio();
    }
}
