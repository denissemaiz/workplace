#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_FRONT.h"
#include "MENUS.h"
#include "EmpleadoDAL.h"


void menuIncio()
{
    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 20);

    mostrar_mensaje ("___________________________", 40, 3);
    mostrar_mensaje ("* BIENVENIDO A WORKPLACE *" ,40, 5);
    mostrar_mensaje ("___________________________", 40, 6);

    EmpleadoDAL reg;
    int dni;

    rlutil::  locate (36,12);
    cout <<"INGRESE SU DNI: ";
    rectangulo (51, 11, 10, 1);
    rlutil::  locate (53,12);
    cin >>dni;

    if (dni == 0000){ ///PONGO UN NUMERO QUE EQUIVALGA A ADMINISTRADOR (1234?)
        system("cls");
        menuAdmin();
    }
    else if (reg.existeDNI(dni)){
        system("cls");
        menuUser();
    } else {
        rlutil::  locate (28,16);
        cout<<"EL DNI INGRESADO NO EXISTE EN NUESTRA BASE DE DATOS.";
        rlutil::  locate (60,21);
        system("pause");
        system("cls");
        menuIncio();
    }
}
