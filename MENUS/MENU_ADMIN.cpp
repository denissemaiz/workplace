#include "MENUS.h"
#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_ADMIN.h"

void menuAdmin()
{
    const char *opciones[] = {"CARGAR EMPLEADO", "MODIFICAR DATOS DEL EMPLEADO", "LISTAR EMPLEADOS", "DEFINIR ESPACIOS",
                              "LISTAR ESPACIOS", "CONSULTAS DE RESERVAS", "INFORMES", "SALIR" };
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        mostrar_mensaje ( " ESTAS SON TUS OPCIONES:  ", 40, 6);
        mostrar_mensaje ("-------------------------", 40, 7);

        rlutil::saveDefaultColor();
        rectangulo (2, 2, 100, 25);
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);
        showItem (opciones[3],30,13,y==3);
        showItem (opciones[4],30,14,y==4);
        showItem (opciones[5],30,15,y==5);
        showItem (opciones[6],30,16,y==6);
        showItem (opciones[7],30,17,y==7);

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

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {
            case 0:     ///CARGAR EMPLEADO
                system("cls");
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("*** CARGAR UN EMPLEADO ***", 40, 5);

                if (agregarEmpleado()!=-1)
                {
                    mostrar_mensaje ("*** REGISTRO AGREGADO ***", 40, 23);
                    getch();
                    system("cls");
                }
                else
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("*** NO SE PUDO AGREGAR EL REGISTRO ***", 33, 11);
                    system("pause>nul");
                    system("cls");
                }
                break;

            case 1:     ///MODIFICAR DATOS EMPLEADO
                system("cls");
                rectangulo (2, 2, 100, 20);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("INGRESE EL DNI DEL EMPLEADO QUE DESEA MODIFICAR: ", 20, 6);

                if(modificarEmpleado())
                {
                    mostrar_mensaje ("*** REGISTRO MODIFICADO ***", 40, 17);
                    getch();
                    system("cls");
                }
                else
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("*** NO SE PUDO MODIFICAR EL REGISTRO ***", 33, 11);
                    system("pause>nul");
                    system("cls");
                }
                break;

            case 2:     ///LISTAR EMPLEADOS
                if(listarEmpleados())
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  FIN DEL LISTADO  ***", 40, 11);
                    system("pause>nul");
                    system("cls");
                }
                else
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  NO EXISTEN REGISTROS DE EMPLEADOS ***", 33, 11);
                    system("pause>nul");
                    system("cls");
                }
                break;

            case 3:     ///DEFINIR ESPACIOS
                system("cls");
                menuLimitarEspacio();
                break;

            case 4:     ///LISTAR ESPACIOS
                system("cls");
                if(listarEspacios())
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  FIN DEL LISTADO  ***", 40, 11);
                    system("pause>nul");
                    system("cls");
                }
                else
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  NO EXISTEN REGISTROS DE ESPACIOS ***", 30, 11);
                    system("pause>nul");
                    system("cls");
                }
                break;

            case 5:
                system("cls");
                consultasReservas();
                break;

            case 6:    ///INFORMES  /**/
                system("cls");
                menuInformes();
                break;

            case 7:   ///SALIR   /**/
                system("cls");
                salirSistemaUser();
                getch();
                return;
                break;
            }
        }
    }
    while(op!=0);
    system("pause>nul");
}
