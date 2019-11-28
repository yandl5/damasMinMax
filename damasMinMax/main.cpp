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
	cout<<"Você deseja jogar o modo pvp ou o modo single player?"<<endl;
	cout<<"Digite 1 para pvp e 2 para single player."<<endl;
	int aux;
	cin>>aux;
	if(aux==1)
	{
		
	}
    criarTabuleiro(dama);
    exibir(dama);
    cout<<"................................................................."<<endl;
    if(aux==1)
	{
		gameTeste(dama);
	}
	else
	{
		pcPlay(dama);
	}
    //campo de testes
    
    //exibir(dama);
    return 0;
}




