#include <random>
#include "randomGenerator.h"
/**
	*@brief Criação do objeto Dado.
	*@details Recebe um valor e estipula o sorteio de 1 até esse valor.
	*@return Objeto dado.
*/
dado::dado(int Valor):rd(), gen(rd()), dis(1, Valor)
{
	valor_dado=std::round(dis(gen));
}
/**
	*@brief Método jogar.
	*@details Baseado no valor informado faz se um sorteio pseudo aleatório.
	*@return Valor do sorteio.
*/
int dado::Jogar()
{
	valor_dado = std::round(dis(gen));
	return valor_dado;	
}
/**
	*@brief Método get do valor.
	*@details 
	*@return Valor do dado.
*/
int dado::getValor()
{
	return valor_dado;
}