#ifndef PECA
#define PECA
//classe peca
class celula
{
private:
    //conte�do da celula
    char valor;
    char tipo;
	//quantidade de pe�as que a celula � capaz de comer
	int x;
	//valor final no destino m�ximo
	int y;
public:
    //construtores
    celula(char Valor);
    celula();
    //destrutor
    ~celula();
    //sets e gets
    void setValor(char Valor);
    void setTipo(char Tipo);
	void setX(int xx);
	void setY(int yy);
    char getValor();
    char getTipo();
	int getX();
	int getY();
};

#endif // PECA
