 #include "functions.h"
int conto=12;
int contx=12;
int contGame=0;
bool pc=false;

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
                dama[i][j].setValor('*');
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
                dama[i][j].setValor('*');
        }
    }
    for (int i=3; i<5; i++)
    {
        for (int j=0; j<8; j++)
        {
            if(i==3 && j%2==0)
                dama[i][j].setValor(' ');
            else
                dama[i][j].setValor('*');

        }
        for (int j=0; j<8; j++)
        {
            if(i==4 && j%2!=0)
                dama[i][j].setValor(' ');
            else if(i==4)
                dama[i][j].setValor('*');

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
        cout<<"movimento não válido"<<endl;
        return;
    }
    char aux;
    //posicao do meio entre as peças.
    int x = inicial.x+((final.x-inicial.x)/2);
    int y= inicial.y+((final.y-inicial.y)/2);
    cout<<x<<" "<<y<<endl;
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
		if(pc=true)
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
void pcPlay()
{
	pc=true;
}
void gerenciadorPC(vector<vector<celula> > &dama)
{
	
}









