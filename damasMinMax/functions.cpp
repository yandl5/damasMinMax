 #include "functions.h"

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
    if(dama[inicial.x][inicial.y].getValor()=='o'||dama[inicial.x][inicial.y].getValor()=='x')
    {
        if(dama[final.x][final.y].getValor()==' ')
        {
        	//não é permitido voltar para trás no movimento simples
        	if(dama[inicial.x][inicial.y].getValor()=='x'&&(inicial.x-final.x==1))
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
    //não é permitido voltar para trás no movimento simples

}
void movimentacaoSimples(vector<vector<celula> > &dama, posicao inicial, posicao final)
{
    if(validadorMovimentacaoSimples(dama,inicial,final)==false)
    {
        cout<<"movimento não válido"<<endl;
        return;
    }
    char aux;
    aux = dama[inicial.x][inicial.y].getValor();
    dama[final.x][final.y].setValor(aux);
    dama[inicial.x][inicial.y].setValor(' ');
}
//comer peça unitária
bool validadorComerPeca(vector<vector<celula> > &dama, posicao inicial, posicao final)
{
    //testando range
    if(testarRange(inicial,final)==false)
    {
        return false;
    }
    if(dama[inicial.x][inicial.y].getValor()=='o'||dama[inicial.x][inicial.y].getValor()=='x')
    {
        if(dama[final.x][final.y].getValor()==' ')
        {
        	//não é permitido voltar para trás no movimento simples
        	int x = inicial.x+((final.x-inicial.x)/2);
    		int y= inicial.y+((final.y-inicial.y)/2);
        	if(dama[inicial.x][inicial.y].getValor()=='x'&&dama[x][y].getValor()=='o')
		    {
		    	return true;
		    }
		    else if(dama[inicial.x][inicial.y].getValor()=='o'&&dama[x][y].getValor()=='x')
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
void comerPecaSimples(vector<vector<celula> > &dama, posicao inicial, posicao final)
{
	if(validadorMovimentacaoSimples(dama,inicial,final)==false)
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
    dama[x][y].setValor(' ');
}

//função de teste provisório
void gameTeste(vector<vector<celula> > &dama)
{
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
    gerenciadorMovimento(dama,inicial,final);
    exibir(dama);
    cout<<"................................................................."<<endl;
    gameTeste(dama);
}
void gerenciadorMovimento(vector<vector<celula> > &dama, posicao inicial, posicao final)
{
	int difX=final.x-inicial.x;
	int difY=final.y-inicial.y;
	//caso de movimentação simples
	if((difX==1||difX==-1)&&(difY==1||difY==-1))
	{
		movimentacaoSimples(dama,inicial,final);
	}
	if((difX==2||difX==-2)&&(difY==2||difY==-2))
	{
		comerPecaSimples(dama,inicial,final);
	}
	else
	{
		cout<<"movimento inválido"<<endl;
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
