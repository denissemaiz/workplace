#include "MENUS.h"
#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_USER.h"
#include "FUNCIONES_RESERVAS.h"

void menuUser(int dni)
{
    system("cls");

    const char *opciones[] = {"RESERVAR","ANULAR RESERVA", "MI HISTORIAL", "SALIR"};

    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);
        rectangulo (2, 2, 100, 20);

        mostrar_mensaje ("__________________________", 40, 3);
        mostrar_mensaje ("* SELECCIONE UNA OPCION *", 40, 5);
        mostrar_mensaje ("__________________________", 40, 6);


        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);
        showItem (opciones[3],30,13,y==3);

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

            if (y>3)
            {
                y=3;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {
            case 0:
                system("cls");
                menuSeleccionarEspacio(dni);
                break;

            case 1:
                system("cls");
                anularReserva(dni);
                break;

            case 2:
                {
                system("cls");
                int respuesta = listarHistorialReservas(dni);
                if(respuesta == 0)
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  NO EXISTEN REGISTROS DE RESERVAS ***", 31, 11);
                    system("pause>nul");
                    system("cls");
                    menuUser(dni);
                }
                else
                {
                    system("cls");
                    rectangulo (2, 2, 100, 20);
                    mostrar_mensaje ("***  FIN DEL LISTADO  ***", 40, 11);
                    system("pause>nul");
                    system("cls");
                    menuUser(dni);
                }
                }
                break;

            case 3:
                system("cls");
                salirSistemaUser();
                getch();
                menuIncio();
                break;
            }
        }
    }
    while(op!=0);
    system("pause>nul");
}


