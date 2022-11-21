#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

#include "rlutil.h"
#include "FUNCIONES.h"
#include "Fecha.h"

void CuadroSeleccionDia()
{

    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje (" POR FAVOR SELECCIONE EL DIA A RESERVAR:", 30, 5);


}

/// RESERVAS


void reservaDesde(Fecha obj)
{


    int d=obj.getDia();
    int m=obj.getMes();
    int a=obj.getAnio();

    if (m==2&&d<=27)
    {
        d+=1;
    }
    if (m==2&&d>27)
    {
        d-=27;
        m+=1;
    }

    if((m==4||m==6||m==9||m==11)&&d<=29)
    {
        d+=1;
    }
    if((m==4||m==6||m==9||m==11)&&d>29)
    {
        d-=29;
        m+=1;
    }

    if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d<=30)
    {
        d+=1;
    }
    if((m==1||m==3||m==5||m==7||m==8||m==10)&&d>30)
    {
        d-=30;
        m+=1;
    }

    if(m==12&&d>30)
    {
        d-=30;
        m=1;
        a+=1;
    }

    obj.setDia(d);
    obj.setMes(m);
    obj.setAnio(a);

    obj.Mostrar();


}


void reservaHasta(Fecha obj)
{


    int d=obj.getDia();
    int m=obj.getMes();
    int a=obj.getAnio();



    if (m==2&&d<=13)
    {
        d+=15;
    }
    if (m==2&&d>13)
    {
        d-=15;
        m+=1;
    }

    if((m==4||m==6||m==9||m==11)&&d<=15)
    {
        d+=15;
    }
    if((m==4||m==6||m==9||m==11)&&d>15)
    {
        d-=15;
        m+=1;
    }

    if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d<=16)
    {
        d+=15;

    }


    if((m==1||m==3||m==5||m==7||m==8||m==10)&&d>=16)
    {
        d-=16;
        m+=1;


    }

    if(m==12&&d>16)
    {
        d-=16;
        m=1;
        a+=1;
    }

    obj.setDia(d);
    obj.setMes(m);
    obj.setAnio(a);

    obj.Mostrar();

}



void CuadroConfirmacionFecha(){
         system("cls");
rectangulo (2, 2, 100, 20);

    mostrar_mensaje ("ESTAS POR RESERVAR UN ESPACIO EN: ", 49, 4);
    mostrar_mensaje ("DIA DE LA RESERVA: ", 49, 5);

    int n=5;
    const char *opciones[] = {"ADMINISTRACION Y RRHH","VENTAS Y MARKETING", "PRODUCCION", "CONTABILIDAD Y FINANZAS", "DIRECCION"};

    mostrar_mensaje ("SECTOR DONDE QUIERE RESERVAR: ", 8, 9);
    mostrar_mensaje ("----------------------------", 8, 10);
    int op=1, y=0;

    rlutil::hidecursor();

    do{

        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);


        showItem (opciones[0],10,12,y==0);
        showItem (opciones[1],10,13,y==1);
        showItem (opciones[2],10,14,y==2);
        showItem (opciones[3],10,15,y==3);
        showItem (opciones[4],10,16,y==4);

        rlutil::locate(6,12+y);
        cout <<"==> " <<endl;


        switch(rlutil::getkey())
        {

        case 14: //UP
            rlutil::locate(6,12+y);
            cout <<"   " <<endl;
            y--;
            if (y<0)
            {
                y=0;
            }

            break;
        case 15: //DOWN
            rlutil::locate(6,12+y);
            cout <<"   " <<endl;
            y++;

            if (y>4)
            {
                y=4;
            }

            break;

        case 1: //ENTER

        ReciboConfirmacionReserva();

            break;

            switch(y)
            {

            case 3:
                op=0;


            }

            break;

        default:

            break;

        }



    }
    while(op!=0);

    system("pause>nul");
}

void ReciboConfirmacionReserva(){
         system("cls");
rectangulo (2, 2, 100, 20);

    mostrar_mensaje ("USTED RESERVO:  ", 40, 4);

    mostrar_mensaje ("ESPACIO: ", 20, 7);
    mostrar_mensaje ("SECTOR: ", 20, 8);
    mostrar_mensaje ("DIA: ", 20, 9);
    mostrar_mensaje ("DESDE LAS: ", 20, 10);
    mostrar_mensaje ("HASTA LAS: ", 20, 11);

    mostrar_mensaje ("CONFIRMA LA RESERVA: ", 40, 18);
    int n=2;
    const char *opciones[] = {"SI","NO"};

  int op=1, y=0;

    rlutil::hidecursor();

    do{

        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);


        showItem (opciones[0],46,19,y==0);
        showItem (opciones[1],46,20,y==1);

        rlutil::locate(42,19+y);
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

        case 1: //ENTER

FechaNoDisponible();
            break;

            switch(y)
            {

            case 2:
                op=0;


            }

            break;

        default:

            break;

        }

    }
    while(op!=0);

    system("pause>nul");
}

void FechaNoDisponible(){
system("cls");
rectangulo (2, 2, 100, 20);

     rlutil::setColor(rlutil::RED);
    mostrar_mensaje ("* LO SENTIMOS NO HAY MAS DISPONIBILIDAD PARA LA FECHA SELECCIONADA *  ", 19, 6);

      int n=2;
    const char *opciones[] = {"VOLVER A CALENDARIO","VOLVER AL MENU PRINCIPAL"};

  int op=1, y=0;

    rlutil::hidecursor();

    do{

        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);


        showItem (opciones[0],35,10,y==0);
        showItem (opciones[1],35,11,y==1);

        rlutil::locate(31,10+y);
        cout <<"==> " <<endl;


        switch(rlutil::getkey())
        {

        case 14: //UP
            rlutil::locate(31,10+y);
            cout <<"    " <<endl;
            y--;
            if (y<0)
            {
                y=0;
            }

            break;
        case 15: //DOWN
            rlutil::locate(31,10+y);
            cout <<"    " <<endl;
            y++;

            if (y>1)
            {
                y=1;
            }

            break;

        case 1: //ENTER

ConfirmacionAnulacion();
            break;

            switch(y)
            {

            case 2:
                op=0;


            }

            break;

        default:

            break;

        }

    }
    while(op!=0);

    system("pause>nul");


}
