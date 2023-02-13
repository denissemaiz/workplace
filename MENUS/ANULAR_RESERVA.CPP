#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_ADMIN.h"
#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_USER.h"
#include "Fecha.h"
#include "MENUS.h"


void anularReserva(int dni)
{
    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 25);

    mostrar_mensaje ("***   ANULANDO RESERVAS   ***", 40, 4);

    mostrar_mensaje (" ESTAS SON TUS RESERVAS ", 20, 6);

    ///  ACA HISTORIAL DE RESERVAS <= AL DIA DE HOY

    /// SELECCIONA UNA RESERVA

    mostrar_mensaje (" ESTAS POR ANULAR ESTA RESERVA ", 20, 15);

    ///MOSTRAR SELECCION


    mostrar_mensaje (" CONFIRMAS LA ANULACION (S/N): ", 40, 18);

    int n=2;
    const char *opciones[] = {"SI","NO"};
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],45,19,y==0);
        showItem (opciones[1],45,20,y==1);

        rlutil::locate(41,19+y);
        cout <<"==> " <<endl;

        switch(rlutil::getkey())
        {
        case 14: //UP
            rlutil::locate(41,19+y);
            cout <<"    " <<endl;
            y--;

            if (y<0)
            {
                y=0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(41,19+y);
            cout <<"    " <<endl;
            y++;

            if (y>1)
            {
                y=1;
            }
            break;

        case 1:         /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {
            case 0:  /// CANCELAR RESERVA

                /// RegResevas poner estado en false: PARA ESTO NECESITA QUE VIAJE: DNI/FECHA/ TIPO DE ESPACIO
                break;

            case 1:     /// VOLVER AL MENU PRINCIPAL
                system("cls");
                {
                    menuUser(dni);
                }

                break;
            }

        }
    }

    while(op!=0);
    system("pause>nul");


}

/*
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
            historialReservas(dni);


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
*/
