#include <iostream>
#include <fstream>
using namespace std;

int dx[8] = {-1,-1,0,1,1,1,0,-1}, dy[8] = {0,1,1,1,0,-1,-1,-1};
int n, m, cat[105][105], mouse[105][105];
bool bin[105][105];
struct punct
{
    int l,c,d;
};
punct coada[32000],x,y;

bool OK(int i, int j, int a[105][105])
{
    if(i<1||j<1||i>n||j>m)
        return false;
    else if(a[i][j] == -1)
        return false;
    return true;
}

void reset()
{
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            bin[i][j] = 0;
}

int Lee(int X, int Y, int XF, int YF, int a[105][105])
{
    reset();
    a[X][Y] = 0;
    bin[X][Y] = 1;
    int inceput = 1, sfarsit = 1;
    coada[inceput].l = X;
    coada[inceput].c = Y;
    coada[inceput].d = 1;
    while(inceput<=sfarsit)
    {
        x = coada[inceput];
        inceput++;
        for(int i = 0; i <= 7; ++i)
        {
            if( OK(x.l+dx[i],x.c+dy[i],a) && bin[x.l+dx[i]][x.c+dy[i]] == 0)
            {
                a[x.l+dx[i]][x.c+dy[i]] = a[x.l][x.c] + 1;
                y.l = x.l + dx[i];
                y.c = x.c + dy[i];
                y.d = x.d + 1;
                bin[y.l][y.c] = 1;
                sfarsit++;
                coada[sfarsit] = y;
                if(y.l == XF && y.c == YF)
                    return a[XF][YF];
            }
        }
    }

}

int main()
{
    ifstream fin("soricel2.in");
    ofstream fout("soricel2.out");
    int k,t,xmouse,nr = 0,z1,z2,ymouse,xcat,ycat, px[1000], py[1000], solx[1000], soly[1000], ok, aux;
    float sol1, sol2;
    fin >> n >> m;
    fin >> xmouse >> ymouse >> xcat >> ycat;
    fin >> k;
    for(int i = 1; i <= k; ++i)
    {
        fin >> px[i] >> py[i];
    }
    fin>>t;
    for(int i = 1; i <= t; ++i)
    {
        fin >> z1 >> z2;
        cat[z1][z2] = -1;
        mouse[z1][z2] = -1;
    }
    int s =0;
    for(int i = 1; i <= k; ++i)
    {
        sol1 = Lee(xmouse,ymouse,px[i],py[i],mouse);
        sol2 = Lee(xcat,ycat,px[i],py[i],cat);
        sol2 = sol2/2;
        if(sol2 > sol1)
        {
            nr++;
            s++;
            solx[s] = px[i];
            soly[s] = py[i];
        }
    }
    fout<<nr<<'\n';
    do
    {
        ok = 1;
        for(int i = 1; i < s; ++i)
        {
            if(solx[i] > solx[i+1])
            {
                aux = solx[i];
                solx[i] = solx[i+1];
                solx[i+1] = aux;
                aux = soly[i];
                soly[i] = soly[i+1];
                soly[i+1] = aux;
                ok = 0;
            }
            else if(solx[i] == solx[i+1] && soly[i] > soly[i+1])
            {
                aux = solx[i];
                solx[i] = solx[i+1];
                solx[i+1] = aux;
                aux = soly[i];
                soly[i] = soly[i+1];
                soly[i+1] = aux;
                ok = 0;
            }
        }
    }
    while(ok==0);
    for(int i = 1; i<=s; ++i)
        fout<<solx[i]<<' '<<soly[i]<<'\n';
}
