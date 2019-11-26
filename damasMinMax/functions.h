#include <vector>
#include <iostream>
#include "celula.h"
using namespace std;
struct posicao
{
	int x;
	int y;
};
void exibir(vector<vector<celula> > dama);
void criarTabuleiro(vector<vector<celula> > &dama);
void movimentacaoSimples(vector<vector<celula> > &dama, posicao inicial, posicao final,bool &flagMultiplo);
bool validadorMovimentacaoSimples(vector<vector<celula> > dama, posicao inicial, posicao final);
void gameTeste(vector<vector<celula> > &dama);
void gerenciadorMovimento(vector<vector<celula> > &dama, posicao inicial, posicao final,bool &flagMultiplo);
bool testarRange(posicao inicial,posicao final);
bool verificarPeca(vector<vector<celula> > &dama, posicao inicial);
bool testeMultiplo(vector<vector<celula> > &dama, posicao final);
void pcPlay();
void gerenciadorPC(vector<vector<celula> > &dama);