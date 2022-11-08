#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES.h"
#include "Fecha.h"
#include "PersonaDTO.h"
#include "PersonaDAL.h"


void CuadroIncio()
{

    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("___________________________", 40, 3);
    mostrar_mensaje ("**BIENVENIDO A WORKPLACE**" ,40, 5);
    mostrar_mensaje ("___________________________", 40, 6);

    int dni;
    rlutil::  locate (30,12);
    cout <<"INGRESE SU DNI: ";
    rlutil::  locate (47,12);
    cin >>dni;
    PersonaDAL reg;
    PersonaDTO aux;

    aux=reg.ObtenerPorDNI(dni);

    if (aux.Getdni() == -1) {
        cout<<"Su dni no existe en nuestra base de datos, intente nuevamente"<<endl;
        system("pause");
        system("cls");
        CuadroIncio();
    }
}

//void DocumentoValido(int dni, int cantidad){
//
//PersonaDAL reg;
//
//for (int i=0;i<cantidad;i++){
//
//    if(reg.Getdni()==dni){
//
//        CuadroIncio();
//    }
//}
//
//
//
//
//
//}
