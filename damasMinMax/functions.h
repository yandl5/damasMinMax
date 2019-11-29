#include <vector>
#include <iostream>
#include "celula.h"
#include "randomGenerator.h"
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
void pcPlay(vector<vector<celula> > &dama);
void gerenciadorPC(vector<vector<celula> > &dama);
void listarPecas(vector<vector<celula> > &dama, vector<posicao> &pecasPC);
int quantidadeMax(vector<vector<celula> > &dama, posicao &peca,posicao &anterior, int x);
bool Teste(vector<vector<celula> > &dama,posicao &inicial, posicao &final);
int calcularY(posicao inicial, vector<string> caminho,vector<vector<celula> > &damaB);
posicao percorrerCaminho(posicao aux, vector<string> caminho, vector<vector<celula> > &damaB);
int verificarPosicaoFinalPeca(posicao aux,vector<vector<celula> > &damaB);
vector<string> pecaMovimentavel(vector<vector<celula> > dama, posicao aux);
string acharMovimento(vector<vector<celula> > damaB, posicao auxiliar,vector<string>,int &maior);
int avaliarCasasVizinhas(vector<vector<celula> > damaB, posicao inicial, string movimento);
int evitarPecaSejaComida(vector<vector<celula> > damaB, posicao inicial, string movimento);
posicao simples(posicao inicial,string movimento);
posicao escolherPeca(vector<posicao> pecas, vector<vector<celula> > dama);
