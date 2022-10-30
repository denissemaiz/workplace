#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

#include "rlutil.h"
#include "FUNCIONES.h"
#include "Fecha.h"

void mostrar_mensaje (string texto, int x, int y)
{

    rlutil::  locate (x,y);
    cout <<texto;
}


void rectangulo (int posx, int posy, int ancho, int alto)
{

/// ABAJO

    for (int x= 1; x <=ancho; x++)
    {

        rlutil::locate( x+ posx, posy);
        cout << (char)205;

        rlutil::locate( x+ posx, posy+alto+1);
        cout << (char)205;
    }

///ANCHO

    for (int y= 1; y <=alto; y++)
    {
        rlutil::locate( posx,  posy+y);
        cout << (char)186;

        rlutil::locate( posx+ancho+1, posy+y);
        cout << (char)186;

    }
///ESQUINAS

    rlutil::locate( posx, posy);
    cout << (char)201;

    rlutil::locate( posx, posy+alto +1);
    cout << (char)200;

    rlutil::locate( posx +ancho +1, posy);
    cout << (char)187;

    rlutil::locate( posx +ancho +1, posy+ alto +1);
    cout << (char)188;

}




void CuadroConfirmacionReserva()
{

    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje (" USTED ESTA RESERVANDO EL DIA:", 30, 5);

    mostrar_mensaje (" ESPACIO:", 10, 8);
    mostrar_mensaje (" DIA:", 10, 10);
    mostrar_mensaje (" HORARIO DE INGRESO:", 10, 12);
    mostrar_mensaje (" HORARIO DE EGRESO:", 10, 14);
    mostrar_mensaje (" PISO/SECTOR DONDE SE REALIZO LA RESERVA:", 10, 16);
    mostrar_mensaje (" ¿CONFIRMA LA RESERVA? :", 10, 18);

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
