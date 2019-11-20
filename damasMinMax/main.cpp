#include "functions.h"
using namespace std;

int main()
{
    //criação vector<vector <celula> > 8X8 de classe célula
    vector<vector<celula> > dama;
    dama.resize(8);
    for(unsigned int i=0;i<dama.size();i++)
    {
        dama[i].resize(8);
    }
    criarTabuleiro(dama);
    exibir(dama);

    //campo de testes
    cout<<"teste de movimentação simples, insira posição inicial: "<<endl;
    posicao inicial;
    posicao final;
    char cast;
    cin>>inicial.x>>cast;
    inicial.y= cast - '0'- 49;
    inicial.x = inicial.x-1;
    cout<<"insira o destino: "<<endl;
    cin>>final.x>>cast;
    final.y=cast - '0'- 49;
    final.x=final.x-1;
    cout<<inicial.y<<" "<<final.y<<endl;
    movimentacaoSimples(dama,inicial,final);
    //exibir(dama);
    return 0;
}




