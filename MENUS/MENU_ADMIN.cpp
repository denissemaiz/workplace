#include "PersonaDAL.h"
#include "PersonaDTO.h"

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_ADMIN.h"


void menuAdmin()
{
    int op;
    while(true)
    {
        system("cls");
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
        system("cls");

        switch(op)
        {
        case 1:
            rectangulo (2, 2, 100, 26);
            rlutil::setColor(rlutil::YELLOW);
            mostrar_mensaje ("CARGAR UN EMPLEADO", 40, 5);
            /**/
            if (agregarEmpleado()==1)
            {
                rlutil::  locate (20,17);
                cout<<"REGISTRO AGREGADO.";   ///NO SE VE ESTE CARTEL
            }
            else
            {
                system("cls");
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("NO SE PUDO AGREGAR EL REGISTRO.", 40, 15);
            }
            break;
        case 2:
        {
            rectangulo (2, 2, 100, 26);
            rlutil::setColor(rlutil::YELLOW);
            mostrar_mensaje (" LISTADO DE EMPLEADOS", 40, 5);
            mostrar_mensaje ("------------------------------", 40, 6);

            PersonaDAL reg;
            int cantidad=reg.cantidadEmpleados();
            PersonaDTO* empleados= new PersonaDTO[cantidad];

            reg.leerEmpleados(empleados, cantidad);

            for( int i=0; i<cantidad; i++)
            {
                empleados[i].mostrar();
            }
            delete[] empleados;
            break;
        }
        case 0:
            return;
            break;

        default:
            cout<<"OPCION INVALIDA"<<endl;
            break;
        }
        cout <<endl;
        rlutil::  locate (10,25);
        system("pause");
    }
    return;
}
