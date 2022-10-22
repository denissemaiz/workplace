#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include <cstring>
#include <ArticuloDAL.h>
#include <ArticuloDTO.h>
#include <cstdio>


class Validaciones
{
    public:
        bool ValidarEntero(char*);
        bool ValidarDecimal(char*);
        bool ValidarCadena(char*);
        bool Validador(int, int);
        int strToIntAll(char *);
        bool Salir(int Op, bool &);
        bool ValidarIdArticulo (int);
        bool CompararCadena (char*,const char*);
    protected:

    private:
};

#endif // VALIDACIONES_H
