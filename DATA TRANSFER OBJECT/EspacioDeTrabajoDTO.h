#ifndef ESPACIODETRABAJODTO_H
#define ESPACIODETRABAJODTO_H


class EspacioDeTrabajoDTO
{
private:
    int _tipo_espacio;
    int _cant_puestos;
    bool _estado;

public:
    EspacioDeTrabajoDTO();

    void setTipo(int tipo);
    void setCantPuestos(int cantpuestos);
    void setEstado(bool estado);

    int getTipo();
    int getCantPuestos();
    bool getEstado();

    void cargar(); /**/
    void mostrar();
};

#endif // ESPACIODETRABAJODTO_H
