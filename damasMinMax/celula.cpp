#include "celula.h"
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
void celula::setZ(int zz)
{
	z=zz;
}
void celula::setCaminho(vector<string> Caminho)
{
	caminho=Caminho;
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
int celula::getZ()
{
	return z;
}
vector<string> celula::getCaminho()
{
	return caminho;
}
void celula::calcularZ()
{
	z=x+y;
}
