#include "celula.h"
celula::celula(char Valor)
{
    valor=Valor;
	x=0;
	y=0;
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
void celula::setX(int xx)
{
	x=xx;
}
void celula::setY(int yy)
{
	y=yy;
}
char celula::getValor()
{
    return valor;
}
char celula::getTipo()
{
    return tipo;
}
int celula::getX()
{
	return x;
}
int celula::getY()
{
	return y;
}
