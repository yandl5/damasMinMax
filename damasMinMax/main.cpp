#include "functions.h"
using namespace std;

int main()
{
    //cria��o vector<vector <celula> > 8X8 de classe c�lula
    vector<vector<celula> > dama;
    dama.resize(8);
    for(unsigned int i=0;i<dama.size();i++)
    {
        dama[i].resize(8);
    }
    criarTabuleiro(dama);
    exibir(dama);
    cout<<"................................................................."<<endl;
    gameTeste(dama);
    //campo de testes
    
    //exibir(dama);
    return 0;
}




