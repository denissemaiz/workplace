#include "PersonaDAL.h"
#include "PersonaDTO.h"

using namespace std;

void CargarEmpleados(){

PersonaDAL reg;



int op,i;

do {

    cout<<"--------------------"<<endl;
    cout<<"1-Cargar Empleado   "<<endl;
    cout<<"2-Listar Empleados"  <<endl;
    cout<<"--------------------"<<endl;
    cout<<"0- SALIR------------"<<endl;
    cout<<"--------------------"<<endl;

    cout<<"Ingrese una opcion"<<endl;
    cin>>op;

    switch(op){

        case 1:{
            cout<<"cargar un empleado"<<endl;

            PersonaDTO empleado;
            empleado.Cargar();
            reg.guardar(empleado);

        }
        break;

        case 2: {
            cout<<"Listar Empleados"<<endl;
            cout<<"---------------"<<endl;
            int cantidad=reg.CantidadEmpleados();
            PersonaDTO* empleados= new PersonaDTO[cantidad];

            reg.leerEmpleados(empleados, cantidad);

            for( int i=0;i<cantidad;i++){

                empleados[i].Mostrar();
            }
            delete[] empleados;
        }
        break;

        case 0:
            cout<<"salir";
        break;
        default:
            cout<<"opcion invalida"<<endl;
        break;

    }


} while(op!=0);


}
















