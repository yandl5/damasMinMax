//Obtido do projeto de LP no qual um dos integrantes do grupo utilizou desse gerador
#ifndef _DADO_H_ 
#define _DADO_H_
#include <random>
using namespace std;
class dado
{
private:
	int valor_dado;
	int tipoDado;
	std::random_device 				rd; 
	std::default_random_engine 		gen; 
	std::uniform_int_distribution<> dis;
public:
	dado(int Valor);
	int Jogar();
	int getValor();	
};

#endif