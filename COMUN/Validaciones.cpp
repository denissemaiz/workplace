#include "Validaciones.h"

bool Validaciones::ValidarEntero(char *Entero)
{
    if(strlen(Entero)<1)
    {
        return false;
    }
    int x = 0;
    while(Entero[x]!='\0')
    {
        if(Entero[x]>=48 && Entero[x]<=57) {}
        else
            return false;
        x++;
    }
    return true;
}

bool Validaciones::ValidarDecimal(char *Decimal)
{
    int punto=0;
    if(strlen(Decimal)<1)
    {
        return false;
    }
    int x = 0;
    if (Decimal[0]==46)
        {
            return false;
        }
    while(Decimal[x]!='\0')
    {
        if((Decimal[x]>=48 && Decimal[x]<=57)||Decimal[x]==46)
        {
            if (Decimal[x]==46)
            {
                punto++;
                if (punto>1)
                {
                    return false;
                }
                x++;
                continue;
            }
        }
        else
            return false;
        x++;
    }
    return true;
}

bool Validaciones::ValidarCadena(char *Cadena)
{
    if(strlen(Cadena)<1)
    {
        return false;
    }
    int x = 0;
    while(Cadena[x]!='\0')
    {
        if(Cadena[x]==-91|| Cadena[x]==-92 ||(Cadena[x]>=65 && Cadena[x]<=90) || (Cadena[x]>=97 && Cadena[x]<=122)|| (Cadena[x]==32)) {}
        else
            return false;
        x++;
    }
    return true;
}

bool Validaciones::Validador(int Op, int CantOp)
{
    for(int x=1; x<=CantOp; x++)
    {
        if (Op==x)
        {
            return true;
        }
    }
    return false;
}
int Validaciones::strToIntAll(char *Cad)
{
    int x=(strlen(Cad)-1), NE=0, M=1;
    while(x!=-1)
    {
        if(Cad[x]>=48 && Cad[x]<=57)
        {
            NE+=((Cad[x]-48)*M);
            x--;
            M*=10;
        }
        else
        {
            NE+=Cad[x]*M;
            x--;
            M*=10;
        }
    }
    return NE;
}

bool Validaciones::Salir(int Op, bool &MensajeS)
{
    if(Op==83 || Op==115)
    {
        return true;
    }
    else if(Op==110 || Op==78)
    {
        MensajeS=true;
        return false;
    }
    else
    {
        return false;
    }
}
bool Validaciones::ValidarIdArticulo(int IdArticulo)
{
    bool encontro=false;
    ArticuloDTO dto;
    FILE *p;
    p = fopen(RUTA_ARTICULO,"rb");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (ArticuloDTO),1,p))
        {
            if(dto.GetIdArticulo()==IdArticulo)
            {
                encontro=true;
                break;
            }
        }
        fclose (p);

    }
    return encontro;
}
bool Validaciones::CompararCadena(char* nombre, const char* ruta)
{
    bool Igual=false;
    ArticuloDTO dto;
    FILE *p;
    p = fopen(ruta,"rb");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (ArticuloDTO),1,p))
        {
            if(strcmp(nombre,dto.GetNombre())==0)
            {
                Igual=true;
                break;
            }
        }
        fclose (p);

    }
    return Igual;
}
