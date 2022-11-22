#include "PersonaDAL.h"
#include "PersonaDTO.h"

using namespace std;

#include "rlutil.h"
#include "FUNCIONES.h"


void cargarEmpleados()
{
    PersonaDAL reg;
    int op, i;
    system("cls");

    do
    {
        rectangulo (2, 2, 100, 26);

        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje (" ¿QUE DESEAS HACER?", 40, 5);
        mostrar_mensaje ("_____________________", 40, 6);

        mostrar_mensaje ("1-CARGAR EMPLEADO", 10, 8);
        mostrar_mensaje ("2-DAR DE BAJA A UN EMPLEADO", 10, 9);
        mostrar_mensaje ("3-REALIZAR UNA RESERVA", 10, 10);
        mostrar_mensaje ("4-LIMITAR ESPACIOS", 10, 11);
        mostrar_mensaje ("5-LISTAR EMPLEADOS", 10, 12);
        mostrar_mensaje ("6-CONSULTA POR USUARIO", 10, 13);
        mostrar_mensaje ("7-CONSULTA DE RESERVAS", 10, 14);
        mostrar_mensaje ("8-IMFORMES", 10, 15);
        mostrar_mensaje ("9-RESPALDOS", 10, 16);
        mostrar_mensaje ("0-SALIR", 10, 17);
        mostrar_mensaje ("SELECCIONE UNA OPCION:", 20, 20);
        rlutil::  locate (43,20);

        cin>>op;

        switch(op)
        {
        case 1:
        {
            system("cls");
            rectangulo (2, 2, 100, 26);
            rlutil::setColor(rlutil::YELLOW);
            mostrar_mensaje (" CARGAR UN EMPLEADO", 40, 5);

            PersonaDTO empleado;
            empleado.cargar();
            reg.guardar(empleado);
        }
        break;

        case 2:
        {
            system("cls");
            
            rlutil::setColor(rlutil::YELLOW);
            mostrar_mensaje (" LISTADO DE EMPLEADOS", 40, 5);
            mostrar_mensaje ("------------------------------", 39, 6);

            int cantidad=reg.cantidadEmpleados();
            PersonaDTO* empleados= new PersonaDTO[cantidad];

            reg.leerEmpleados(empleados, cantidad);

            for( int i=0; i<cantidad; i++)
            {

                empleados[i].mostrar();
            }
            delete[] empleados;
        }

        break;

        case 0:
            cout<<"SALIR";
            break;

        default:
            cout<<"OPCION INVALIDA"<<endl;
            break;
        }
    }

    while(op!=0);
}
