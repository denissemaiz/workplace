#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "FUNCIONES_USER.h"

bool validarDni(int dni)
{
    int cifras=0;

    while(dni > 0)
    {
        dni = dni / 10;
        cifras++;
    }

    if(cifras==8)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void salirSistemaUser()
{
    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****   MUCHAS GRACIAS POR USAR NUESTRO SISTEMA *****", 28, 10);
    mostrar_mensaje ("By CIBERNAUTAS", 68, 20);
}

