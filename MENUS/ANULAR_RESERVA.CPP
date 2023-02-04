#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_ADMIN.h"
#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_USER.h"
#include "Fecha.h"


void anularReserva()
{
    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::WHITE);
    rectangulo (28, 4, 33, 1);

    mostrar_mensaje (" ESTAS POR ANULAR UNA RESERVA ", 30, 5);
    mostrar_mensaje (" RESERVAS FUTURAS A ANULAR: ", 10, 9);
    mostrar_mensaje (" CONFIRMAS LA ANULACION (S/N): ", 10, 15);
}


void confirmacionAnulacion()
{
    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::WHITE);

    mostrar_mensaje (" ACABAS DE ANULAR LA SIGUIENTE RESERVA: ", 10, 6);
    mostrar_mensaje (" MOTIVO DE LA ANULACION: ", 10, 8);

    int n=2;
    const char *opciones[] = {"CANCELAR","VOLVER AL MENU PRINCIPAL"};
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],20,15,y==0);
        showItem (opciones[1],20,16,y==1);

        rlutil::locate(16,15+y);
        cout <<"==> " <<endl;

        switch(rlutil::getkey())
        {
        case 14: //UP
            rlutil::locate(16,15+y);
            cout <<"    " <<endl;
            y--;

            if (y<0)
            {
                y=0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(16,15+y);
            cout <<"    " <<endl;
            y++;

            if (y>1)
            {
                y=1;
            }
            break;

        case 1:         /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):
            historialReservas();


            switch(y)
            {
                case 0:  /// CANCELAR RESERVA

                 break;

            case 1:     /// VOLVER AL MENU PRINCIPAL

            //menuUser();
                 break;
            }

        }
    }

    while(op!=0);
    system("pause>nul");
}
