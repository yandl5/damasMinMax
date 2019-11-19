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
    int v;
    cout<<"digite (1) se voce quer jogar contra o computador ou digite (2) se voce quer jogar player vs player: ";
    cin>> v;

    return 0;
}




