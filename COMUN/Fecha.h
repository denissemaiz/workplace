#ifndef FECHA_H
#define FECHA_H


class Fecha
{
private:
    int dia;
    int mes;
    int anio;
public:

    // CONSTRUCTOR:
    Fecha();

    // SET:
    void Setdia(int dia);
    void Setmes(int mes);
    void Setanio(int anio);

    // GET:
    int Getdia();
    int Getmes();
    int Getanio();
};

#endif // FECHA_H
