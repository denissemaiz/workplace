#include "Ingresos.h"

void Ingresos::getline(char *cadena,int cantidad)
{
    int contador =0;
    char caracter ='\0';
    while(caracter!=10)
    {
        caracter = std::cin.get();
        if(contador != cantidad && caracter!=10)
        {
            cadena[contador] = caracter;
            contador++;
        }
    }
    cadena[contador]='\0';
}

