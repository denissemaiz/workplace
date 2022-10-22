#ifndef HORA_H
#define HORA_H


class Hora
{
private:
    int horas;
    int minutos;
public:

    // CONSTRUCTOR:
    Hora();

    // SET:
    void Sethoras(int horas);
    void Setminutos(int minutos);

// GET:
    int Gethoras();
    int Getminutos();
};

#endif // HORA_H
