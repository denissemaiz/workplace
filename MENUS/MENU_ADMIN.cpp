#include "PersonaDAL.h"
#include "PersonaDTO.h"

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_FRONT.h"
#include "MENUS.h"
#include "FUNCIONES_ADMIN.h"

/*
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
        mostrar_mensaje ("0-SALIR", 10, 17);  ///AGREGAR OPCIÓN "ATRÁS"?

        mostrar_mensaje ("SELECCIONE UNA OPCION:", 20, 20);
        rlutil::  locate (43,20);

        cin>>op;
        system("cls");
*/
///PANTALLA MENU ADMIN
void menuAdmin()
{

    rectangulo (2, 2, 100, 20);
    int n=10;
    const char *opciones[] = {"CARGAR EMPLEADO","DAR DE BAJA EMPLEADO","REALIZAR UNA RESERVA", "DEFINIR ESPACIOS", "LIMITAR ESPACIOS", "LISTAR EMPLEADOS","CONSULTAS POR USUARIO","CONSULTAS DE RESERVAS","INFORMES","RESPALDOS","SALIR"};

    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        mostrar_mensaje ("HOLA, ADMIN!!!! ESTAS SON TUS OPCIONES: ", 40, 5);
        mostrar_mensaje ("________________________________________", 40, 6);

        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);
        showItem (opciones[3],30,13,y==3);
        showItem (opciones[4],30,14,y==4);
        showItem (opciones[5],30,15,y==5);
        showItem (opciones[6],30,16,y==6);
        showItem (opciones[7],30,17,y==7);
        showItem (opciones[8],30,18,y==8);
        showItem (opciones[9],30,19,y==9);

        rlutil::locate(26,10+y);
        cout <<"==> " <<endl;

        switch(rlutil::getkey())
        {
        case 14: //UP
            rlutil::locate(26,10+y);
            cout <<"   " <<endl;
            y--;

            if (y<0)
            {
                y=0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(26,10+y);
            cout <<"   " <<endl;
            y++;

            if (y>9)
            {
                y=9;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {
            case 0:     ///CARGAR EMPLEADO
                system("cls");
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("CARGAR UN EMPLEADO", 40, 5);
                if (agregarEmpleado()==-1)
                {
                    rlutil::  locate (20,23);
                    cout<<"REGISTRO AGREGADO.";
                }
                else
                {
                    system("cls");
                    rectangulo (2, 2, 100, 26);
                    rlutil::setColor(rlutil::YELLOW);
                    mostrar_mensaje ("NO SE PUDO AGREGAR EL REGISTRO.", 20, 14);
                }
                break;

            case 1:     ///DAR DE BAJA EMPLEADO
                system("cls");

                break;

            case 2:    ///REALIZAR UNA RESERVA
                system("cls");

                break;

            case 3:     ///DEFINIR ESPACIOS
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("DEFINIR ESPACIOS", 40, 5);
                cuadroLimitarEspacio(y);
                break;

            case 4:    ///LIMITAR ESPACIOS
                system("cls");
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("LIMITAR ESPACIOS", 40, 5);
                cuadroLimitarEspacio(y);
                break;

            case 5:     ///LISTAR EMPLEADOS
                system("cls");

                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("LISTAR EMPLEADOS", 40, 5);
                if(listarEmpleados())
                {
                    system("cls");
                    rectangulo (2, 2, 100, 26);
                    rlutil::setColor(rlutil::YELLOW);
                    mostrar_mensaje ("FIN DEL LISTADO.", 26, 14);
                }
                else
                {
                    rlutil::  locate (20,23);
                    cout<<"NO EXISTEN REGISTROS DE EMPLEADOS.";
                }
                break;

            case 6:     ///CONSULTAS POR USUARIO
                system("cls");

                break;

            case 7:    ///CONSULTAS DE RESERVAS
                system("cls");

                break;

            case 8:   ///INFORMES
                system("cls");

                break;

            case 9:    ///RESPALDOS
                system("cls");

                break;

            case 10:  ///SALIR
                system("cls");
                break;
            }
        }
    }
    while(op!=0);
    system("pause>nul");
}





/*

/// esto estaba anidado:
switch(op)
{
case 1:
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("CARGAR UN EMPLEADO", 40, 5);
    if (agregarEmpleado()==-1)
    {
        rlutil::  locate (20,23);
        cout<<"REGISTRO AGREGADO.";
    }
    else
    {
        system("cls");
        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("NO SE PUDO AGREGAR EL REGISTRO.", 38, 14);
    }
    break;
case 2:
{
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("DAR DE BAJA A UN EMPLEADO", 40, 5);
    mostrar_mensaje ("LISTADO DE EMPLEADOS", 40, 7);
    mostrar_mensaje ("------------------------------", 40, 8);

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
case 5:
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("LISTAR EMPLEADOS", 40, 5);
    if(listarEmpleados())
    {
        system("cls");
        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("FIN DEL LISTADO.", 45, 14);
    }
    else
    {
        rlutil::  locate (20,23);
        cout<<"NO EXISTEN REGISTROS DE EMPLEADOS.";
    }
    break;
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
*/
