#include "MENUS.h"
#include "FUNCIONES_ADMIN.h"
#include "FUNCIONES_USER.h"
#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_RESERVAS.h"


void consultasReservas()
{
    system("cls");
    const char *opciones[] = {"DNI","LEGAJO", "ESPACIO DE TRABAJO", "VOLVER AL MENU PRINCIPAL"};

    mostrar_mensaje ("**** OPCIONES DE CONSULTAS ****", 40, 5);
    mostrar_mensaje ("-------------------------------", 40, 6);
    mostrar_mensaje ( "CONSULTAR POR:  ", 20, 10);

    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 20);
    rlutil::setColor(rlutil::YELLOW);

    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        showItem (opciones[0],30,12,y==0);
        showItem (opciones[1],30,13,y==1);
        showItem (opciones[2],30,14,y==2);
        showItem (opciones[3],30,15,y==3);

        rlutil::locate(26,12+y);
        cout <<"==> " <<endl;

        switch(rlutil::getkey())
        {
        case 14: //UP
            rlutil::locate(26,12+y);
            cout <<"   " <<endl;
            y--;

            if (y<0)
            {
                y=0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(26,12+y);
            cout <<"   " <<endl;
            y++;

            if (y>3)
            {
                y=3;
            }
            break;

        case 1:   /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {
            case 0:      ///DNI
            {
                system("cls");
                rectangulo (2, 2, 100, 20);
                int respuesta = listarPorDni();

                if(respuesta == -1)
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  EL DNI INGRESADO ES INCORRECTO ***", 33, 11);
                    system("pause>nul");
                    system("cls");
                    consultasReservas();
                }
                else if(respuesta == 0)
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  NO EXISTEN REGISTROS DE RESERVAS ***", 31, 11);
                    system("pause>nul");
                    system("cls");
                    menuAdmin();
                }
                else
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  FIN DEL LISTADO  ***", 40, 11);
                    system("pause>nul");
                    system("cls");
                    menuAdmin();
                }
            }
            break;

            case 1:       ///LEGAJO
            {
                system("cls");
                rectangulo (2, 2, 100, 20);
                int respuesta = listarPorLegajo();

                if(respuesta == -1)
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  EL LEGAJO INGRESADO ES INCORRECTO ***", 31, 11);
                    system("pause>nul");
                    system("cls");
                    consultasReservas();
                }
                else if(respuesta == 0)
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  NO EXISTEN REGISTROS DE RESERVAS ***", 31, 11);
                    system("pause>nul");
                    system("cls");
                    menuAdmin();
                }
                else
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  FIN DEL LISTADO  ***", 40, 11);
                    system("pause>nul");
                    system("cls");
                    menuAdmin();
                }
            }
            break;

            case 2:       ///ESPACIO DE TRABAJO
            {
                system("cls");
                rectangulo (2, 2, 100, 20);
                int respuesta = listarPorEspacio();

                if(respuesta == -1)
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  EL ESPACIO DE TRABAJO INGRESADO NO EXISTE ***", 31, 11);
                    system("pause>nul");
                    system("cls");
                    consultasReservas();
                }
                else if(respuesta == 0)
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  NO EXISTEN REGISTROS DE RESERVAS ***", 31, 11);
                    system("pause>nul");
                    system("cls");
                    menuAdmin();
                }
                else
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  FIN DEL LISTADO  ***", 40, 11);
                    system("pause>nul");
                    system("cls");
                    menuAdmin();
                }
            }
            break;

            case 3:     /// SALIR
                system("cls");
                op=0;
                menuAdmin();
                break;
            }
        }
    }

    while(op!=0);
    system("pause>nul");
}
