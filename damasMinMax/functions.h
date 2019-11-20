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
void movimentacaoSimples(vector<vector<celula> > &dama, posicao inicial, posicao final);
bool validadorMovimentacaoSimples(vector<vector<celula> > dama, posicao inicial, posicao final);