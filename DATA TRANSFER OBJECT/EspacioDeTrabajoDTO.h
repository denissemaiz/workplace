#ifndef ESPACIODETRABAJODTO_H
#define ESPACIODETRABAJODTO_H


class EspacioDeTrabajoDTO
{
private:
    int _tipo_espacio;
    int _cant_puestos;  ///total
    int _disponibilidad;   ///lo que puede usar
    bool _estado;   ///dar de baja un espacio

public:
    EspacioDeTrabajoDTO();

    void setTipo(int tipo);
    void setCantPuestos(int cantpuestos);
    void setDisponibilidad(int cap);
    void setEstado(int estado);

    int getTipo();
    int getCantPuestos();
    int getDisponibilidad();
    bool getEstado();

    void cargar();
    void mostrar();
};

#endif // ESPACIODETRABAJODTO_H
