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

