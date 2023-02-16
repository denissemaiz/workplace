#include "MENUS.h"
#include "FUNCIONES_FRONT.h"

bool menuConfirmarReserva(int espacio, Fecha fecha)
{
    system("cls");
    rectangulo (2, 2, 100, 20);

    mostrar_mensaje ("USTED SELECCIONO:  ", 42, 4);
    mostrar_mensaje ("ESPACIO: ", 22, 9);
    switch(espacio)
    {
    case 0:
        cout<<"DESK";
        break;
    case 1:
        cout<<"SALA DE REUNIONES";
        break;
    case 2:
        cout<<"ESTACIONAMIENTO";
        break;
    case 3:
        cout<<"COMEDOR";
        break;
    }
    mostrar_mensaje ("DIA: ", 22, 10);
    fecha.Mostrar();
    mostrar_mensaje ("CONFIRMA LA RESERVA: ", 40, 14);

    int op=1, y=0;
    const char *opciones[] = {"SI","NO"};

    rlutil::hidecursor();

    do
    {
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],49,16,y==0);
        showItem (opciones[1],49,17,y==1);

        rlutil::locate(45,16+y);
        cout <<"==> " <<endl;

        switch(rlutil::getkey())
        {
        case 14: //UP
            rlutil::locate(42,19+y);
            cout <<"    " <<endl;
            y--;

            if (y<0)
            {
                y=0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(42,19+y);
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
            case 0:     /// SI CONFIRMA
                return true;
                break;
            case 1:      /// NO CONFIRMA
                return false;
                break;
            }
        }
    }
    while(op!=0);
    system("pause>nul");
    return false;
}
