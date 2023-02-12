#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "MENUS.h"
#include "FUNCIONES_ADMIN.h"
#include "FUNCIONES_USER.h"
#include "FUNCIONES_FRONT.h"
#include "Fecha.h"


void Informes()
{
    system("cls");
    int n=5;
    const char *opciones[] = {"DESK","SALA DE REUNIONES", "ESTACIONAMIENTO", "COMEDOR","VOLVER AL MENU PRINCIPAL"};

    mostrar_mensaje ("**** OPCIONES DE INFORMES ****", 40, 5);
    mostrar_mensaje ("------------------------------", 40, 6);

    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    int op=1, y=0;

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

            if (y>5)
            {
                y=5;
            }
            break;

        case 1:   /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {
            case 0:      /// DESK
                system("cls");
                {
                    InformeDesk();
                }
                break;

            case 1:       /// SALA DE REUNIONES
                system("cls");
                        {
                        InformeSalaReuniones();
                        }
                break;

            case 2:       /// ESTACIONAMIENTO
                system("cls");

               {
                   InformeEstacionamiento();
               }
                break;

            case 3:     /// COMEDOR
                system("cls");
                {
                InformeComedor();
                    }

                break;

            case 4:     /// VOLVER AL MENU PRINCIPAL
                system("cls");
                {
                    menuAdmin();
                }
                break;

            }
        }
    }

    while(op!=0);
    system("pause>nul");
}

void InformePlantilla()
{

    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    mostrar_mensaje ("**** INFORME SOBRE ESPACIO: ", 30, 5);
    mostrar_mensaje ("-----------------------------------------------------------------", 20, 6);


    mostrar_mensaje ("-TOTAL DE RESERVAS: ", 5, 11);
    mostrar_mensaje ("-PORCENTAJE SOBRE TOTAL DISPONIBLES: ", 5, 12);
    mostrar_mensaje ("-PORCENTAJE SOBRE TOTAL DE RESERVAS: ", 5, 13);
    mostrar_mensaje ("-RESERVAS ANULADAS: ", 5, 15);
    mostrar_mensaje ("-RESERVAS DE INVITADOS EXTERNOS: ", 5, 16);
    mostrar_mensaje ("-RESERVAS POR SECTOR:", 5, 18);
    mostrar_mensaje ("1-ADM. Y RRHH: ", 8, 19);
    mostrar_mensaje ("2-MARKETING Y VENTAS: ", 8, 20);
    mostrar_mensaje ("3-PRODUCCION Y SISTEMAS: ", 8, 21);
    mostrar_mensaje ("4-CONTABILIDAD Y FINANZAS: ", 8, 22);
    mostrar_mensaje ("5-DIRECCION: ", 8, 23);


}

void InformeDesk()
{
    mostrar_mensaje ("DESK ****", 58, 5);
    mostrar_mensaje ("MES: ", 46, 8);
    InformePlantilla();




    getch();
    system("cls");
}

void InformeSalaReuniones()
{
    mostrar_mensaje ("SALA DE REUNIONES ****", 58, 5);
    mostrar_mensaje ("MES: ", 46, 8);
    InformePlantilla();




    getch();
    system("cls");
}
void InformeEstacionamiento()
{
    mostrar_mensaje ("ESTACIONAMIENTO ****", 58, 5);
    mostrar_mensaje ("MES: ", 46, 8);
    InformePlantilla();




    getch();
    system("cls");
}
void InformeComedor()
{
    mostrar_mensaje ("COMEDOR ****", 58, 5);
    mostrar_mensaje ("MES: ", 46, 8);
    InformePlantilla();




    getch();
    system("cls");
}
