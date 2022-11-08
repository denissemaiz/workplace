#ifndef ESPACIODETRABAJODTO_H
#define ESPACIODETRABAJODTO_H


class EspacioDeTrabajoDTO
{
   private:
       char _nombre[30];
       int _tipo_espacio;
       int _cantidaddepuestos;
       int _capacidad;
       bool _estado_espacio;

   public:
       EspacioDeTrabajoDTO();
        void Setnombre(char *nombre);
        void Settipodeespacio(int tipoespacio);
        void Setcantidadpuestos(int cantidadpuestos);
        void Setcapacidad(int cap);
        void Setestadoespacio(int estadoespacio);

        const char* Getnombre();
        int Gettipoespacio();
        int Getcantidadpuestos();
        int Getcapacidad();
        bool Getestadoespacio();

        void cargar();
        void mostrar();
};

#endif // ESPACIODETRABAJODTO_H
