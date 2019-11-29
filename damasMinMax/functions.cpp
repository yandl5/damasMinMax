 #include "functions.h"
int conto=12;
int contx=12;
int contGame=0;
bool pc=false;
vector<string> iaCaminho;

void criarTabuleiro(vector<vector<celula> > &dama)
{
	for (int i=0; i<3; i++)
    {
        for (int j=0; j<8; j++)
        {
            if(i%2==0 && j%2!=0 )
            {
                dama[i][j].setValor('x');
            }
            else if(i%2!=0 && j%2==0)
            {
                dama[i][j].setValor('x');

            }
            else
                dama[i][j].setValor('|');
        }
    }
    for (int i=5; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if(i%2==0 && j%2!=0 )
            {
                dama[i][j].setValor('o');
            }
            else if(i%2!=0 && j%2==0)
            {
                dama[i][j].setValor('o');

            }
            else
                dama[i][j].setValor('|');
        }
    }
    for (int i=3; i<5; i++)
    {
        for (int j=0; j<8; j++)
        {
            if(i==3 && j%2==0)
                dama[i][j].setValor(' ');
            else
                dama[i][j].setValor('|');

        }
        for (int j=0; j<8; j++)
        {
            if(i==4 && j%2!=0)
                dama[i][j].setValor(' ');
            else if(i==4)
                dama[i][j].setValor('|');

        }
    }
}
void exibir(vector<vector<celula> > dama)
{
    cout<<"    a   b   c   d   e   f   g   h"<<endl;
    cout<<"  |---|---|---|---|---|---|---|---|"<<endl;
    for (int i=0; i<8; i++)
    {
        cout<<i+1<<" | ";

        for (int j=0; j<8; j++)
        {
            cout<<dama[i][j].getValor()<<" | ";

        }

        cout<<endl;
        cout<<"  |---|---|---|---|---|---|---|---|"<<endl;
    }
}
bool validadorMovimentacaoSimples(vector<vector<celula> > dama, posicao inicial, posicao final)
{
    //testando range
    if(testarRange(inicial,final)==false)
    {
        return false;
    }
    //testar movimento
    if(dama[inicial.x][inicial.y].getValor()!=' '&&dama[inicial.x][inicial.y].getValor()!='*')
    {
        if(dama[final.x][final.y].getValor()==' ')
        {
			if(dama[inicial.x][inicial.y].getTipo()=='d')
			{
				return true;
			}
        	//não é permitido voltar para trás no movimento simples
        	else if(dama[inicial.x][inicial.y].getValor()=='x'&&(inicial.x-final.x==1))
		    {
		    	cout<<"Não é permitido voltar em movimento simples"<<endl;
		    	return false;
		    }
		    else if(dama[inicial.x][inicial.y].getValor()=='o'&&(inicial.x-final.x==-1))
		    {
		    	cout<<"Não é permitido voltar em movimento simples"<<endl;
		    	return false;
		    }
		    else
		    {
            	return true;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

}
void movimentacaoSimples(vector<vector<celula> > &dama, posicao inicial, posicao final)
{
    if(validadorMovimentacaoSimples(dama,inicial,final)==false)
    {
        cout<<"movimento não válido"<<endl;
		exibir(dama);
        gameTeste(dama);
    }
    char aux;
    aux = dama[inicial.x][inicial.y].getValor();
    dama[final.x][final.y].setValor(aux);
    dama[inicial.x][inicial.y].setValor(' ');
	//verifica se a peça era uma dama
	if(dama[inicial.x][inicial.y].getTipo()=='d')
	{
		dama[inicial.x][inicial.y].setTipo(' ');
		dama[final.x][final.y].setTipo('d');
	}
	
	//teste para promoção de peça em dama
	if(final.x==0&&dama[final.x][final.y].getValor()=='o')
	{
		dama[final.x][final.y].setTipo('d');
		dama[final.x][final.y].setValor('O');
	}
	if(final.x==7&&dama[final.x][final.y].getValor()=='x')
	{
		dama[final.x][final.y].setTipo('d');
		dama[final.x][final.y].setValor('X');
	}
}
//comer peça unitária
bool validadorComerPeca(vector<vector<celula> > &dama, posicao inicial, posicao final)
{
    //testando range
    if(testarRange(inicial,final)==false)
    {
        return false;
    }
    if(dama[inicial.x][inicial.y].getValor()!=' '&&dama[inicial.x][inicial.y].getValor()!='*')
    {
        if(dama[final.x][final.y].getValor()==' ')
        {
			//verificar peça meio
        	int x = inicial.x+((final.x-inicial.x)/2);
    		int y= inicial.y+((final.y-inicial.y)/2);
			//verificar as 4 possibilidades
        	if(dama[inicial.x][inicial.y].getValor()=='x'&&(dama[x][y].getValor()=='o'||dama[x][y].getValor()=='O'))
		    {
		    	return true;
		    }
		    else if(dama[inicial.x][inicial.y].getValor()=='o'&&(dama[x][y].getValor()=='x'||dama[x][y].getValor()=='X'))
		    {
		    	return true;
		    }
			else if(dama[inicial.x][inicial.y].getValor()=='X'&&(dama[x][y].getValor()=='o'||dama[x][y].getValor()=='O'))
			{
				return  true;
			}
			else if(dama[inicial.x][inicial.y].getValor()=='O'&&(dama[x][y].getValor()=='x'||dama[x][y].getValor()=='X'))
			{
				return true;
			}
		    else
		    {
            	return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }	
}
void comerPecaSimples(vector<vector<celula> > &dama, posicao inicial, posicao final,bool &flagMultiplo)
{
	if(validadorComerPeca(dama,inicial,final)==false)
    {
        return;
    }
    char aux;
    //posicao do meio entre as peças.
    int x = inicial.x+((final.x-inicial.x)/2);
    int y= inicial.y+((final.y-inicial.y)/2);
    //cout<<x<<" "<<y<<endl;
    aux = dama[inicial.x][inicial.y].getValor();
    dama[final.x][final.y].setValor(aux);
    dama[inicial.x][inicial.y].setValor(' ');
    if(dama[x][y].getValor()=='x'||dama[x][y].getValor()=='X')
    {
    	contx--;
    }
    else
    {
    	conto--;
    }
    dama[x][y].setValor(' ');
    flagMultiplo=true;
	//verifica se a peça era uma dama
	if(dama[inicial.x][inicial.y].getTipo()=='d')
	{
		dama[inicial.x][inicial.y].setTipo(' ');
		dama[final.x][final.y].setTipo('d');
	}
	
	//teste para promoção de peça em dama
	if(final.x==0&&dama[final.x][final.y].getValor()=='o')
	{
		dama[final.x][final.y].setTipo('d');
		dama[final.x][final.y].setValor('O');
	}
	if(final.x==7&&dama[final.x][final.y].getValor()=='x')
	{
		dama[final.x][final.y].setTipo('d');
		dama[final.x][final.y].setValor('X');
	}
	//verifica se a peça comida era um dama
	if(dama[x][y].getTipo()=='d')
	{
		dama[x][y].setTipo(' ');
	}
}

//função de teste provisório
void gameTeste(vector<vector<celula> > &dama)
{
	//verificar vitória(o):
	if(conto==0)
	{
		cout<<"Vitória jogador 1(o)"<<endl;
		return;
	}
	//verificar vitória(x)
	else if(contx==0)
	{
		cout<<"Vitória jogador 2(x)"<<endl;
		return;
	}
	//movimentos pares são bola
	if(contGame%2==0)
	{
		cout<<"Jogador 1(o) faça seu movimento: "<<endl;
	}
	//movimento ímpar são x, com a ressalva que o pc só assume x
	else
	{
		if(pc==true)
		{
			cout<<"O computador está computando o movimento..."<<endl;
			gerenciadorPC(dama);
		}
		else
		{
			cout<<"Jogador 2(x) faça seu movimento: "<<endl;
		}
	}
	//receber peça e destino.
	cout<<"Posição inicial: "<<endl;
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

    //verificar se a peça é válida, se corresponde ao turno
    if(!verificarPeca(dama,inicial))
    {
    	cout<<"Peça selecionada inválida, escolha uma peça válida"<<endl;
    	gameTeste(dama);
    }
    //verificar se o jogador pode jogar novamente, válido após comer uma peça e tenha outra possível para comer
    bool flagMultiplo;
    gerenciadorMovimento(dama,inicial,final,flagMultiplo);
    exibir(dama);
    testeMultiplo(dama,final);
    if(flagMultiplo)
    {
		if(testeMultiplo(dama,final)){
			cout<<"................................................................."<<endl;
    		gameTeste(dama);
		}
    }
    else
    {
    	contGame++;
		cout<<"................................................................."<<endl;
    	gameTeste(dama);
    }
	contGame++;
    cout<<"................................................................."<<endl;
    gameTeste(dama);
}
void gerenciadorMovimento(vector<vector<celula> > &dama, posicao inicial, posicao final,bool &flagMultiplo)
{
	int difX=final.x-inicial.x;
	int difY=final.y-inicial.y;
	//caso de movimentação simples
	if((difX==1||difX==-1)&&(difY==1||difY==-1))
	{
		movimentacaoSimples(dama,inicial,final);
		flagMultiplo=false;
	}
	else if((difX==2||difX==-2)&&(difY==2||difY==-2))
	{
		comerPecaSimples(dama,inicial,final,flagMultiplo);
	}
	else
	{
		cout<<"movimento inválido"<<endl;
		gameTeste(dama);
	}
}

//testar range
bool testarRange(posicao inicial, posicao final)
{
	if(inicial.x<0||inicial.x>7||inicial.y<0||inicial.y>7||final.x<0||final.x>7||final.y<0||final.y>7)
    {
        return false;
    }
    else
    {
    	return true;
    }
}
bool verificarPeca(vector<vector<celula> > &dama, posicao inicial)
{
	if(contGame%2==0&&(dama[inicial.x][inicial.y].getValor()=='o'||dama[inicial.x][inicial.y].getValor()=='O'))
	{
		return true;
	}
	else if(contGame%2==1&&(dama[inicial.x][inicial.y].getValor()=='x'||dama[inicial.x][inicial.y].getValor()=='X'))
	{
		return true;
	}
	return false;
}
bool testeMultiplo(vector<vector<celula> > &dama, posicao final)
{
	//(+2,+2),(+2,-2),(-2,+2),(-2,-2).
	posicao a;
	a.x=final.x+2;
	a.y=final.y+2;
	if(validadorComerPeca(dama,final,a))
	{
		return true;
	}
	a.x=final.x+2;
	a.y=final.y-2;
	if(validadorComerPeca(dama,final,a))
	{
		return true;
	}
	a.x=final.x-2;
	a.y=final.y+2;
	if(validadorComerPeca(dama,final,a))
	{
		return true;
	}
	a.x=final.x-2;
	a.y=final.y-2;
	if(validadorComerPeca(dama,final,a))
	{
		return true;
	}
	return false;
}

//Parte de IA do computador
//primeira chamada só para fixar o jogo entre homem e pc
void pcPlay(vector<vector<celula> > &dama)
{
	pc=true;
	gameTeste(dama);
}
//gerenciador base do pc
void gerenciadorPC(vector<vector<celula> > &dama)
{
	//melhor peça
	posicao melhorPeca;
	//posicao auxiliar para movimentação simples
	vector<string> posicoes;
	//primeiro é necessário contabilizar todas as peças x ou X do tabuleiro, serão anotadas em um vector<posicao>
	vector<posicao> pecasPC;
	listarPecas(dama,pecasPC);
	//verificar a quantidade de peças que cada célula é capaz de comer
	vector<vector<celula> > damaB = dama;
	for(unsigned int i=0;i<pecasPC.size();i++)
	{
		vector<vector<celula> > damaB = dama;
		dama[pecasPC[i].x][pecasPC[i].y].setX(quantidadeMax(dama,pecasPC[i],pecasPC[i],0));
		dama[pecasPC[i].x][pecasPC[i].y].setCaminho(iaCaminho);
		dama[pecasPC[i].x][pecasPC[i].y].setY(calcularY(pecasPC[i],iaCaminho,damaB));
		if(iaCaminho.size()==0)
		{
			posicoes=pecaMovimentavel(dama,pecasPC[i]);
			if(posicoes.size()!=0)
			{
				int maior;
				iaCaminho.push_back(acharMovimento(damaB,pecasPC[i],posicoes,maior));
				dama[pecasPC[i].x][pecasPC[i].y].setZ(maior);
				dama[pecasPC[i].x][pecasPC[i].y].setCaminho(iaCaminho);
			}
			else
			{
				dama[pecasPC[i].x][pecasPC[i].y].setZ(-10);
			}
		}
		else
		{
			dama[pecasPC[i].x][pecasPC[i].y].calcularZ();
		}
		cout<<"Valor da peça "<< pecasPC[i].x<<" "<<pecasPC[i].y<<" | "<<dama[pecasPC[i].x][pecasPC[i].y].getZ()<<endl;
		posicoes.clear();
		iaCaminho.clear();
		damaB=dama;
	}
	//eleger a melhor peça, com base na pontuação
	melhorPeca = escolherPeca(pecasPC,dama);
	cout<<"Peça escolhida "<< melhorPeca.x<<" "<<melhorPeca.y<<" | "<<dama[melhorPeca.x][melhorPeca.y].getZ()<<endl;
}
//lista todas as peças do pc em campo
void listarPecas(vector<vector<celula> > &dama, vector<posicao> &pecasPC)
{
	posicao aux;
	for(unsigned int i=0; i<dama.size();i++)
	{
		for(unsigned int j=0;j<dama[i].size();j++)
		{
			if(dama[i][j].getValor()=='x'||dama[i][j].getValor()=='X')
			{
				aux.x=i;
				aux.y=j;
				pecasPC.push_back(aux);
			}
		}
	}
}
//função que verifica a quantidade de peças q uma célula pode comer
int quantidadeMax(vector<vector<celula> > &dama, posicao &peca, posicao &anterior, int x)
{
	posicao aux;

	//pode comer na direção nordeste?
	aux.x = peca.x-2;
	aux.y = peca.y+2;
	if(Teste(dama,peca,aux))
	{
		if(aux.x!=anterior.x || aux.y!=anterior.y)
		{
			iaCaminho.push_back("NE");
			return quantidadeMax(dama,aux,peca,x+1);
		}
	}
	aux.x = peca.x+2;
	aux.y = peca.y+2;
	//pode comer na direção sudeste?
	if(Teste(dama,peca,aux))
	{
		if(aux.x!=anterior.x || aux.y!=anterior.y)
		{
			iaCaminho.push_back("SE");
			return quantidadeMax(dama,aux,peca,x+1);
		}
	}
	aux.x = peca.x-2;
	aux.y = peca.y-2;
	//pode comer na direção noroeste?
	if(Teste(dama,peca,aux))
	{
		if(aux.x!=anterior.x || aux.y!=anterior.y)
		{
			iaCaminho.push_back("NO");
			return quantidadeMax(dama,aux,peca,x+1);
		}
	}
	aux.x = peca.x+2;
	aux.y = peca.y-2;
	//pode comer na direção sudoeste?
	if(Teste(dama,peca,aux))
	{
		if(aux.x!=anterior.x || aux.y!=anterior.y)
		{
			iaCaminho.push_back("SO");
			return quantidadeMax(dama,aux,peca,x+1);
		}
	}
	return x;
}
//pode comer para pc.
bool Teste(vector<vector<celula> > &dama,posicao &inicial, posicao &final)
{
	if(testarRange(inicial,final))
	{
		int x = inicial.x+((final.x-inicial.x)/2);
    	int y = inicial.y+((final.y-inicial.y)/2);
    	if(dama[x][y].getValor()=='o'||dama[x][y].getValor()=='O')
    	{
    		if(dama[final.x][final.y].getValor()==' ')
    		{
    			return true;
    		}
    		else
    		{
    			return false;
    		}
    	}
    	else
    	{
    		return false;
    	}
	}
	return false;
}
int calcularY(posicao inicial, vector<string> caminho,vector<vector<celula> > &damaB)
{
	if(caminho.size()==0)
	{
		return 1;
	}
	posicao aux = percorrerCaminho(inicial,caminho,damaB);
	int y = verificarPosicaoFinalPeca(aux,damaB);
	return y;
}
posicao percorrerCaminho(posicao aux, vector<string> caminho, vector<vector<celula> > &damaB)
{
	char valorInicial = damaB[aux.x][aux.y].getValor();
	for(unsigned int i=0;i<caminho.size();i++)
	{
		if(caminho[i]=="NE")
		{
			damaB[aux.x][aux.y].setValor(' ');
			damaB[aux.x-1][aux.y+1].setValor(' ');
			aux.x = aux.x-2;
			aux.y = aux.y+2;
		}
		else if(caminho[i]=="NO")
		{
			damaB[aux.x][aux.y].setValor(' ');
			damaB[aux.x-1][aux.y-1].setValor(' ');
			aux.x = aux.x-2;
			aux.y = aux.y-2;
		}
		else if(caminho[i]=="SO")
		{
			damaB[aux.x][aux.y].setValor(' ');
			damaB[aux.x+1][aux.y-1].setValor(' ');
			aux.x = aux.x+2;
			aux.y = aux.y-2;
		}
		else if(caminho[i]=="SE")
		{
			damaB[aux.x][aux.y].setValor(' ');
			damaB[aux.x+1][aux.y+1].setValor(' ');
			aux.x = aux.x+2;
			aux.y = aux.y+2;
		}
		damaB[aux.x][aux.y].setValor(valorInicial);
	}
	return aux;
}
int verificarPosicaoFinalPeca(posicao aux,vector<vector<celula> > &damaB)
{
	posicao peca;
	posicao oposta;
	//verifica se a nordeste existe uma 'o' que possa comer a peça em questão
	peca.x=aux.x-1;
	peca.y=aux.y+1;
	oposta.x=aux.x+1;
	oposta.y=aux.x-1;
	bool a = true;
	if(validadorComerPeca(damaB,peca,oposta))
	{
		comerPecaSimples(damaB,peca,oposta,a);
		if(testeMultiplo(damaB,oposta))
		{
			return -4;
		}
		else
		{
			return -2;
		}
	}
	//verifica se a noroeste existe uma 'o' que possa comer a peça em questão
	peca.x=aux.x-1;
	peca.y=aux.y-1;
	oposta.x=aux.x+1;
	oposta.y=aux.y+1;
	if(validadorComerPeca(damaB,peca,oposta))
	{
		comerPecaSimples(damaB,peca,oposta,a);
		if(testeMultiplo(damaB,oposta))
		{
			return -4;
		}
		else
		{
			return -2;
		}
	}
	//verifica se a sudeste existe uma 'o' que possa comer a peça em questão
	oposta.x=aux.x-1;
	oposta.y=aux.y-1;
	peca.x=aux.x+1;
	peca.y=aux.y+1;
	if(validadorComerPeca(damaB,peca,oposta))
	{
		comerPecaSimples(damaB,peca,oposta,a);
		if(testeMultiplo(damaB,oposta))
		{
			return -4;
		}
		else
		{
			return -2;
		}
	}
	//verifica se a sudoeste existe uma 'o' que possa comer a peça em questão
	oposta.x=aux.x-1;
	oposta.y=aux.y+1;
	peca.x=aux.x+1;
	peca.y=aux.y-1;
	if(validadorComerPeca(damaB,peca,oposta))
	{
		comerPecaSimples(damaB,peca,oposta,a);
		if(testeMultiplo(damaB,oposta))
		{
			return -4;
		}
		else
		{
			return -2;
		}
	}
	return 2;
}
vector<string> pecaMovimentavel(vector<vector<celula> > dama, posicao aux)
{
	vector<string> posicoes;
	//testar se a peça pode se movimentar ou comer em alguma posição
	//NE
	posicao teste;
	teste.x= aux.x-1;
	teste.y=aux.y+1;
	if(dama[aux.x][aux.y].getValor()=='X')
	{
		if(testarRange(teste,aux))
		{
			if(dama[aux.x-1][aux.y+1].getValor()==' ')
			{
				posicoes.push_back("NE");
			}
		}
	}
	//NO
	teste.x = aux.x-1;
	teste.y=aux.y -1;
	if(dama[aux.x][aux.y].getValor()=='X')
	{
		if(testarRange(teste,aux))
		{
			if(dama[aux.x-1][aux.y-1].getValor()==' ')
			{
				posicoes.push_back("NO");
			}
		}
	}
	//SE
	teste.x= aux.x+1;
	teste.y=aux.y+1;
	if(testarRange(teste,aux))
	{
		if(dama[aux.x+1][aux.y+1].getValor()==' ')
		{
			posicoes.push_back("SE");
		}
	}
	//SO
	teste.x= aux.x+1;
	teste.y=aux.y-1;
	if(testarRange(teste,aux))
	{
		if(dama[aux.x+1][aux.y-1].getValor()==' ')
		{
			posicoes.push_back("SO");
		}
	}
	return posicoes;
}
string acharMovimento(vector<vector<celula> > damaB, posicao aux, vector<string> posicoes,int &maior)
{
	posicao envio;
	vector<int> scores;
	vector<vector<celula> > copia = damaB;
	vector<vector<celula> > copiaB = damaB;
	char valorInicial;
	int a,b,c;
	//verificar os scores de cada movimentação
	for(unsigned int i=0;i<posicoes.size();i++)
	{
		if(posicoes[i]=="NE")
		{
			envio.x=aux.x-1;
			envio.y=aux.y+1;
			if(testarRange(envio,aux))
			{
				valorInicial = copia[aux.x][aux.y].getValor();
				copia[aux.x][aux.y].setValor(' ');
				copia[envio.x][envio.y].setValor(valorInicial);
				copiaB=copia;
				a = verificarPosicaoFinalPeca(envio,copia);
				b = avaliarCasasVizinhas(copia,aux,posicoes[i]);
				c = evitarPecaSejaComida(copia,aux, posicoes[i]);
				scores.push_back(a+b+c);
			}
		}
		else if(posicoes[i]=="SE")
		{
			envio.x=aux.x+1;
			envio.y=aux.y+1;
			if(testarRange(envio,aux))
			{
				valorInicial = copia[aux.x][aux.y].getValor();
				copia[aux.x][aux.y].setValor(' ');
				copia[envio.x][envio.y].setValor(valorInicial);
				copiaB=copia;
				a = verificarPosicaoFinalPeca(envio,copia);
				b = avaliarCasasVizinhas(copia,aux,posicoes[i]);
				c = evitarPecaSejaComida(copia,aux, posicoes[i]);
				scores.push_back(a+b+c);
			}
		}
		else if(posicoes[i]=="NO")
		{
			envio.x=aux.x-1;
			envio.y=aux.y-1;
			if(testarRange(envio,aux))
			{
				valorInicial = copia[aux.x][aux.y].getValor();
				copia[aux.x][aux.y].setValor(' ');
				copia[envio.x][envio.y].setValor(valorInicial);
				copiaB=copia;
				a = verificarPosicaoFinalPeca(envio,copia);
				b = avaliarCasasVizinhas(copia,aux,posicoes[i]);
				c = evitarPecaSejaComida(copia,aux, posicoes[i]);
				scores.push_back(a+b+c);
			}
		}
		else if(posicoes[i]=="SO")
		{
			envio.x=aux.x+1;
			envio.y=aux.y-1;
			if(testarRange(envio,aux))
			{
				valorInicial = copia[aux.x][aux.y].getValor();
				copia[aux.x][aux.y].setValor(' ');
				copia[envio.x][envio.y].setValor(valorInicial);
				copiaB=copia;
				a = verificarPosicaoFinalPeca(envio,copia);
				b = avaliarCasasVizinhas(copia,aux,posicoes[i]);
				c = evitarPecaSejaComida(copia,aux, posicoes[i]);
				scores.push_back(a+b+c);
			}
		}
		copia=damaB;
	}
	//verificar se há um maior score unico
	maior=scores[0];
	vector<string> maiores;
	for(unsigned int i=0;i<scores.size();i++)
	{
		if(scores[i]>maior)
		{
			maiores.clear();
			maiores.push_back(posicoes[i]);
			maior = scores[i];
		}
		else if(scores[i]==maior)
		{
			maiores.push_back(posicoes[i]);
		}
	}
	//com os maiores em mãos caso o tamanho do vector seja maior que 1, desempate por aleatoriedade
	if(maiores.size()==1)
	{
		return maiores[0];
	}
	else
	{
		dado sorteio(maiores.size());
		return maiores[sorteio.Jogar()-1];
	}
}
int avaliarCasasVizinhas(vector<vector<celula> > damaB, posicao inicial, string movimento)
{
	vector<posicao> posicoes;
	posicao aux;
	int valor=0;
	//anotar inicialmente todas as peças ao redor da peça
	//NO
	aux.x = inicial.x-1;
	aux.y = inicial.y-1;
	if((damaB[aux.x][aux.y].getValor()=='x'||damaB[aux.x][aux.y].getValor()=='X')&&movimento!="NO")
	{
		posicoes.push_back(aux);
	}
	//NE
	aux.x = inicial.x-1;
	aux.y = inicial.y+1;
	if((damaB[aux.x][aux.y].getValor()=='x'||damaB[aux.x][aux.y].getValor()=='X')&&movimento!="NE")
	{
		posicoes.push_back(aux);
	}
	//SO
	aux.x = inicial.x+1;
	aux.y = inicial.y-1;
	if((damaB[aux.x][aux.y].getValor()=='x'||damaB[aux.x][aux.y].getValor()=='X')&&movimento!="SO")
	{
		posicoes.push_back(aux);
	}
	//SE
	aux.x = inicial.x+1;
	aux.y = inicial.y+1;
	if((damaB[aux.x][aux.y].getValor()=='x'||damaB[aux.x][aux.y].getValor()=='X')&&movimento!="SE")
	{
		posicoes.push_back(aux);
	}
	//realizar o movimento no tabuleiro e avaliar o comportamento das peças
	//verificar as peças
	vector<vector<celula> > copia = damaB;
	for(unsigned int i=0;i<posicoes.size();i++)
	{
		valor = verificarPosicaoFinalPeca(posicoes[i],copia);
		if(valor!=2)
		{
			return valor;
		}
		copia=damaB;
	}
	return 0;
}
int evitarPecaSejaComida(vector<vector<celula> > damaB, posicao inicial, string movimento)
{
	posicao aux;
	posicao atual;
	vector<posicao> posicoes;
	vector<vector<celula> > copia;
	int valor=0;
	//onde a celula se encontra?
	atual = simples(inicial,movimento);
	//lista as peças alaidas ao redor da celula
	copia = damaB;
	copia[atual.x][atual.y].setValor(' ');
	//NO
	aux.x = atual.x-1;
	aux.y = atual.y-1;
	if(damaB[aux.x][aux.y].getValor()=='x'||damaB[aux.x][aux.y].getValor()=='X')
	{
		posicoes.push_back(aux);
	}
	//NE
	aux.x = atual.x-1;
	aux.y = atual.y+1;
	if(damaB[aux.x][aux.y].getValor()=='x'||damaB[aux.x][aux.y].getValor()=='X')
	{
		posicoes.push_back(aux);
	}
	//SO
	aux.x = atual.x+1;
	aux.y = atual.y-1;
	if(damaB[aux.x][aux.y].getValor()=='x'||damaB[aux.x][aux.y].getValor()=='X')
	{
		posicoes.push_back(aux);
	}
	//SE
	aux.x = atual.x+1;
	aux.y = atual.y+1;
	if(damaB[aux.x][aux.y].getValor()=='x'||damaB[aux.x][aux.y].getValor()=='X')
	{
		posicoes.push_back(aux);
	}
	//verificar se as posições obtidas são válidas
	for(unsigned int i=0;i<posicoes.size();i++)
	{
		if(!testarRange(posicoes[i],posicoes[i]))
		{
			posicoes.erase(posicoes.begin()+i);
		}
	}
	//com as posições listadas e a celula apagada vamos verificar se alguma dessas peças pode ser comida
	vector<vector<celula> > envio = copia;
	for(unsigned int i=0; i<posicoes.size();i++)
	{
		valor = verificarPosicaoFinalPeca(posicoes[i],envio);
		if(valor!=2)
		{
			return 2;
		}
		envio=copia;
	}
	return 0;
}
posicao simples(posicao inicial,string movimento)
{
	posicao aux;
	if(movimento=="NE")
	{
		aux.x=inicial.x-1;
		aux.y=inicial.y+1;
	}
	else if(movimento=="NO")
	{
		aux.x=inicial.x-1;
		aux.y=inicial.y-1;
	}
	else if(movimento=="SE")
	{
		aux.x=inicial.x+1;
		aux.y=inicial.y+1;
	}
	else if(movimento=="SO")
	{
		aux.x=inicial.x+1;
		aux.y=inicial.y-1;
	}
	return aux;
}
posicao escolherPeca(vector<posicao> pecas, vector<vector<celula> > dama)
{
	int maior;
	vector<posicao> maiores;
	maior = dama[pecas[0].x][pecas[0].y].getZ();
	for(unsigned int i=0;i<pecas.size();i++)
	{
		if(dama[pecas[i].x][pecas[i].y].getZ()>maior)
		{
			maiores.clear();
			maiores.push_back(pecas[i]);
			maior = dama[pecas[i].x][pecas[i].y].getZ();
		}
		else if(dama[pecas[i].x][pecas[i].y].getZ()==maior)
		{
			maiores.push_back(pecas[i]);
		}
	}
	//com os maiores em mãos caso o tamanho do vector seja maior que 1, desempate por aleatoriedade
	if(maiores.size()==1)
	{
		return maiores[0];
	}
	else
	{
		dado sorteio(maiores.size());
		return maiores[sorteio.Jogar()-1];
	}
}
//percorrer, definir se a celula é simples ou complexa e fazer uma função para cada percorrimento.









