#include "celula.h"
celula::celula(char Valor)
{
    valor=Valor;
}
celula::celula(){}
celula::~celula(){}
void celula::setValor(char Valor)
{
    valor=Valor;
}
void celula::setTipo(char Tipo)
{
    tipo=Tipo;
}
char celula::getValor()
{
    return valor;
}
char celula::getTipo()
{
    return tipo;
}
