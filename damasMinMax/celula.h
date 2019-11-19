#ifndef PECA
#define PECA
//classe peca
class celula
{
private:
    //conteúdo da celula
    char valor;
    char tipo;
public:
    //construtores
    celula(char Valor);
    celula();
    //destrutor
    ~celula();
    //sets e gets
    void setValor(char Valor);
    void setTipo(char Tipo);
    char getValor();
    char getTipo();
};

#endif // PECA
