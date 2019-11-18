#include<iostream>
using namespace std;
void exibir(char dama [][8]);
void criarTabuleiro(char dama [8][8]);
int main()
{
    char dama[8][8];
    criarTabuleiro(dama);
    exibir(dama);
    int v;
    cout<<"digite (1) se voce quer jogar contra o computador ou digite (2) se voce quer jogar player vs player: ";
    cin>> v;
    
    return 0;
}
void criarTabuleiro(char dama [8][8])
{
	for (int i=0; i<3; i++)
    {
        for (int j=0; j<8; j++)
        {
            if(i%2==0 && j%2!=0 )
            {
                dama[i][j]='x';
            }
            else if(i%2!=0 && j%2==0)
            {
                dama[i][j]='x';

            }
            else
                dama[i][j]='*';
        }
    }
    for (int i=5; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if(i%2==0 && j%2!=0 )
            {
                dama[i][j]='o';
            }
            else if(i%2!=0 && j%2==0)
            {
                dama[i][j]='o';

            }
            else
                dama[i][j]='*';
        }
    }
    for (int i=3; i<5; i++)
    {
        for (int j=0; j<8; j++)
        {
            if(i==3 && j%2==0)
                dama[i][j]=' ';
            else
                dama[i][j]='*';

        }
        for (int j=0; j<8; j++)
        {
            if(i==4 && j%2!=0)
                dama[i][j]=' ';
            else if(i==4)
                dama[i][j]='*';

        }
    }
}
void exibir(char dama [][8])
{
    cout<<"    a   b   c   d   e   f   g   h"<<endl;
    cout<<"  |---|---|---|---|---|---|---|---|"<<endl;
    for (int i=0; i<8; i++)
    {
        cout<<i+1<<" | ";

        for (int j=0; j<8; j++)
        {
            cout<<dama[i][j]<<" | ";

        }

        cout<<endl;
        cout<<"  |---|---|---|---|---|---|---|---|"<<endl;
    }
}


