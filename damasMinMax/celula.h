#ifndef PECA
#define PECA
//classe peca
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class celula
{
private:
    //conteúdo da celula
    char valor;
    char tipo;
	//quantidade de peças que a celula é capaz de comer
	int x;
	//valor da penalidade da posição final
	int y;
	//valor correspondente a heuristica z=x+y;
	int z;
	//caminho da célula até destino máximo
	vector<string> caminho;
	

public:
    //construtor
    celula();
    //destrutor
    ~celula();
    //sets e gets
    void setValor(char Valor);
    void setTipo(char Tipo);
	void setX(int xx);
	void setY(int yy);
	void setZ(int zz);
	void setCaminho(vector<string> Caminho);
    char getValor();
    char getTipo();
	int getX();
	int getY();
	int getZ();
	vector<string> getCaminho();
	void calcularZ();
};

#endif // PECA
