#ifndef PERSONADTO_H
#define PERSONADTO_H

class PersonaDTO
{
protected:
    int _dni;
    char _nombre[50];
    char _apellido[50];
    char _email[50];
    int _telefono;

public:
    PersonaDTO();

    void setDni(int dni);
    void setNombre(char *nombre);
    void setApellido(char *apellido);
    void setEmail(char *email);
    void setTelefono(int telefono);

    int getDni();
    char * getNombre();
    char * getApellido();
    char * getEmail();
    int getTelefono();

    void cargar(int dni);
    void mostrar(int dni);
};

#endif // PERSONADTO_H
