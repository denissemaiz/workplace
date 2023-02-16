#include "MENUS.h"
#include "FUNCIONES_ADMIN.h"
#include "FUNCIONES_USER.h"
#include "FUNCIONES_FRONT.h"
#include "EmpleadoDAL.h"

bool menuModificarDatos(int nroRegistro)
{
    system("cls");

    const char *opciones[] = {"DNI", "NOMBRE", "APELLIDO", "EMAIL", "TELEFONO", "LEGAJO", "SECTOR", "DAR DE BAJA/ALTA", "VOLVER AL MENU PRINCIPAL"};

    mostrar_mensaje ("* MODIFICAR DATOS DEL EMPLEADO *", 40, 4);
    mostrar_mensaje ("--------------------------------", 40, 5);
    mostrar_mensaje ("* SELECCIONE EL DATO QUE DESEA MODIFICAR *", 25, 8);

    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    int op=1, y=0;

    int _dni,_telefono, _legajo, _sector, opc;
    char _nombre[50],_apellido[50],_email[50];
    bool _estado, modifico = false;

    EmpleadoDAL regEmpleado;
    EmpleadoDTO objEmpleado;

    int cantidad=regEmpleado.getCantidad();
    EmpleadoDTO* vecEmpleados= new EmpleadoDTO[cantidad];

    regEmpleado.leerTodos(vecEmpleados, cantidad);

    rlutil::hidecursor();

    do
    {
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

            if (y>7)
            {
                y=7;
            }
            break;

        case 1:   /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {
            case 0:      /// SETEAR DNI
                system("cls");
                rectangulo (2, 2, 100, 20);
                mostrar_mensaje ("INGRESE EL DNI NUEVO: ", 20, 6);
                mostrar_mensaje ("DNI: ", 20, 9);
                cin>>_dni;
                vecEmpleados[nroRegistro].setDni(_dni);
                modifico = regEmpleado.modificar(vecEmpleados[nroRegistro], nroRegistro);
                break;

            case 1:   /// SETEAR NOMBRE
                system("cls");
                rectangulo (2, 2, 100, 20);
                mostrar_mensaje ("INGRESE EL NOMBRE NUEVO: ", 20, 6);
                mostrar_mensaje ("NOMBRE: ", 20, 9);
                cin>>_nombre;
                vecEmpleados[nroRegistro].setNombre(_nombre);
                modifico = regEmpleado.modificar(vecEmpleados[nroRegistro], nroRegistro);
                break;

            case 2:          /// SETEAR APELLIDO
                system("cls");
                rectangulo (2, 2, 100, 20);
                mostrar_mensaje ("INGRESE EL APELLIDO NUEVO: ", 20, 6);
                mostrar_mensaje ("APELLIDO: ", 20, 9);
                cin>>_apellido;
                vecEmpleados[nroRegistro].setApellido(_apellido);
                modifico = regEmpleado.modificar(vecEmpleados[nroRegistro], nroRegistro);
                break;

            case 3:     /// SETEAR EMAIL
                system("cls");
                rectangulo (2, 2, 100, 20);
                mostrar_mensaje ("INGRESE EL EMAIL NUEVO: ", 20, 6);
                mostrar_mensaje ("EMAIL: ", 20, 9);
                cin>>_email;
                vecEmpleados[nroRegistro].setEmail(_email);
                modifico = regEmpleado.modificar(vecEmpleados[nroRegistro], nroRegistro);
                break;

            case 4:     /// SETEAR TELEFONO
                system("cls");
                rectangulo (2, 2, 100, 20);
                mostrar_mensaje ("INGRESE EL TELEFONO NUEVO: ", 20, 6);
                mostrar_mensaje ("TELEFONO: ", 20, 9);
                cin>>_telefono;
                vecEmpleados[nroRegistro].setTelefono(_telefono);
                modifico = regEmpleado.modificar(vecEmpleados[nroRegistro], nroRegistro);
                break;

            case 5:     /// SETEAR LEGAJO
                system("cls");
                rectangulo (2, 2, 100, 20);
                mostrar_mensaje ("INGRESE EL LEGAJO NUEVO: ", 20, 6);
                mostrar_mensaje ("LEGAJO: ", 20, 9);
                cin>>_legajo;
                vecEmpleados[nroRegistro].setLegajo(_legajo);
                modifico = regEmpleado.modificar(vecEmpleados[nroRegistro], nroRegistro);
                break;

            case 6:     /// SETEAR SECTOR
                system("cls");
                rectangulo (2, 2, 100, 20);
                mostrar_mensaje ("INGRESE EL SECTOR NUEVO: ", 20, 6);
                mostrar_mensaje ("SECTOR: ", 20, 9);
                rlutil::  locate (21,11);
                cout<<"1- ADMINISTRACION Y RRHH";
                rlutil::  locate (21,12);
                cout<<"2- MARKETING Y VENTAS";
                rlutil::  locate (21,13);
                cout<<"3- PRODUCCION Y SISTEMAS";
                rlutil::  locate (21,14);
                cout<<"4- CONTABILIDAD Y FINANZAS";
                rlutil::  locate (21,15);
                cout<<"5- GERENCIA Y DIRECCION";
                rlutil::  locate (28,9);
                cin>>_sector;
                if(_sector<1 || _sector>5)
                {
                    modifico = false;
                }
                else
                {
                    vecEmpleados[nroRegistro].setSector(_sector);
                    modifico = regEmpleado.modificar(vecEmpleados[nroRegistro], nroRegistro);
                }
                break;

            case 7:     /// SETEAR DAR DE BAJA
                system("cls");
                rectangulo (2, 2, 100, 20);
                rlutil::  locate (20,9);
                cout<<"QUE DESEA HACER?: ";
                rlutil::  locate (21,11);
                cout<<"1- DAR DE BAJA";
                rlutil::  locate (21,12);
                cout<<"2- DAR DE ALTA";
                rlutil::  locate (38,9);
                cin>>opc;
                if(opc == 1)
                {
                    _estado=false;
                }
                else if(opc == 2)
                {
                    _estado=true;
                }
                else
                {
                    return modifico;
                }
                vecEmpleados[nroRegistro].setEstado(_estado);
                modifico = regEmpleado.modificar(vecEmpleados[nroRegistro], nroRegistro);
                break;

            case 8:     /// VOLVER AL MENU PRINCIPAL
                system("cls");
                menuAdmin();
                break;
            }
            return modifico;
        }
    }
    while(op!=0);
    system("pause>nul");
    return modifico; /**/
}

