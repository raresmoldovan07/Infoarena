#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("wow.in");
ofstream fout("wow.out");

int a[105][105], b[105][105];
bool bin[105][105];
int n, m, p, X, Y, X2, Y2, inceput, sfarsit;
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

struct punct
{
    int l,c,d;
};
punct coada[32000],x,y;

void reset()
{
    for(int i =  1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            bin[i][j] = 0;
}

bool OK(int i, int j)
{
    if(i>n || j>m || i<1 || j<1)
        return false;
    else if(a[i][j] == -1)
        return false;
    return true;
}

void Lee()
{
    a[X][Y] = 0;
    bin[X][Y] = 1;
    inceput = 1;
    sfarsit = 1;
    coada[inceput].l = X;
    coada[inceput].c = Y;
    coada[inceput].d = 1;
    while(inceput<=sfarsit)
    {
        x = coada[inceput];
        inceput++;
        for(int i = 0; i < 4; ++i)
        {
            if(bin[x.l+dx[i]][x.c+dy[i]] == 0 && OK(x.l+dx[i],x.c+dy[i]) )
            {
                a[x.l+dx[i]][x.c+dy[i]] = a[x.l][x.c] + 1;
                y.l = x.l + dx[i];
                y.c = x.c + dy[i];
                y.d = x.d + 1;
                bin[y.l][y.c] = 1;
                sfarsit++;
                coada[sfarsit] = y;

            }
        }
    }
}
void aduna()
{
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            b[i][j] = b[i][j] + a[i][j];
}

void Read()
{
    fin >> n >> m >> p;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            fin >> a[i][j];
            if(a[i][j])
                a[i][j] = -1;
        }
    for(int k = 1; k <= p; ++k)
    {
        fin >> X >> Y;
        X++;
        Y++;
        reset();
        Lee();
        aduna();
    }
}

int main()
{
    Read();
    int minn = 1000000, xmin, ymin;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(b[i][j]< minn && b[i][j]>0)
            {
                minn = b[i][j];
                xmin = i -1;
                ymin = j -1;
            }


    fout<<minn<<'\n';
    fout<<xmin<<' '<<ymin;
}
