#ifndef ESPACIODETRABAJODTO_H
#define ESPACIODETRABAJODTO_H


class EspacioDeTrabajoDTO
{
private:
    char _nombre[30];
    int _tipo_espacio;
    int _cant_puestos;
    int _capacidad;
    bool _estado;

public:
    EspacioDeTrabajoDTO();

    void setNombre(char *nombre);
    void setTipo(int tipo);
    void setCantPuestos(int cantpuestos);
    void setCapacidad(int cap);
    void setEstado(int estado);

    const char* getNombre();
    int getTipo();
    int getCantPuestos();
    int getCapacidad();
    bool getEstado();

    void cargar();
    void mostrar();
};

#endif // ESPACIODETRABAJODTO_H
