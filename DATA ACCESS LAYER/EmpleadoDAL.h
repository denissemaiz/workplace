#ifndef EMPLEADODAL_H
#define EMPLEADODAL_H
#include <cstdio>
#include "../DATA TRANSFER OBJECT/EmpleadoDTO.h"

class EmpleadoDAL
{
public:
    // METODOS:
    bool existe(const char*);
    bool agregar (EmpleadoDTO);
    bool modificar (EmpleadoDTO);
    bool eliminar (EmpleadoDTO);
    int obtenerTamanio(); /*es igual a cantidad empleados?*/ /**/
    EmpleadoDTO buscarRegistro(int,int);
    EmpleadoDTO obtenerPorDNI (int);
    int leerDeDisco(int pos);
    bool existeDNI(int);
    int cantidadEmpleados();
    void leerEmpleados(EmpleadoDTO empleados[], int cant);
};

#endif // EMPLEADODAL_H
