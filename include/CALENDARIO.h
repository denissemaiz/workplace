#ifndef CALENDARIO_H
#define CALENDARIO_H


class CALENDARIO
{
        private:

                int _dia, _mes, _anio;

        public:
        int  getDia();
        int  getMes();
        int  getAnio();
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);

             CALENDARIO();
        std::string toString();
        void Mostrar();
        void Cargar();




};

#endif // CALENDARIO_H
