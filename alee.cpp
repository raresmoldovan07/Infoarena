#include<iostream>
#include<stdio.h>
#include <fstream>

using namespace std;
const int x2[4]={0,0,1,-1};
const int y2[4]={1,-1,0,0};
int a[178][178],x1,y1,n,m,x0,y0,i,j,u,t,inceput=1,sfarsit=1, lin, col, val;

struct punct
{
    int l,c,d;
};
punct coada[100000];
int main()
{
    ifstream fin("alee.in");
    ofstream fout("alee.out");
    fin >> n >> m;
    for(i = 1;i <= m; i++)
    {
        fin >> u >> t;
        a[u][t]=-1;
    }
    fin >> x0 >> y0 >> x1 >> y1;
    for(i = 0;i <= n+1; i++)
    {
        a[0][i] = -1;
        a[i][0] = -1;
        a[i][n+1] = -1;
        a[n+1][i] = -1;
    }
    coada[inceput].l=x0;
    coada[inceput].c=y0;
    coada[inceput].d=1;
    a[x0][y0]=1;
    while(inceput<=sfarsit)
    {
        lin = coada[inceput].l;
        col = coada[inceput].c;
        val = coada[inceput].d;

        for(int k = 0; k < 4; k++)
        {
            if(a[lin+x2[k]][col+y2[k]]==0)
            {
                a[lin+x2[k]][col+y2[k]]=val+1;
                sfarsit++;
                coada[sfarsit].l = lin + x2[k];
                coada[sfarsit].c = col + y2[k];
                coada[sfarsit].d = val+1;
                if(lin+x2[k] == x1 && col+y2[k] == y1)
                {
                    fout<<a[lin+x2[k]][col+y2[k]];
                    fout<<endl;
                    for(int i = inceput; i <= sfarsit; ++i)
                        fout<<coada[i].l<<' '<<coada[i].c<<endl;
                 break;
                }
            }
        }

    }
}
