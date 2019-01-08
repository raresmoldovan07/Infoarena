#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

ifstream f("rj.in");
ofstream g("rj.out");

struct punct
{
    int l, c, d;
};
int dx[8] = {-1,-1,0,1,1,1,0,-1}, dy[8] = {0,1,1,1,0,-1,-1,-1};
punct coada[32000], x, y;
char s[105];
int  n, m,bin[105][105],xr,yr,xj,yj,jul[105][105], rom[105][105];

void reset()
{
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        bin[i][j] = 0;
}
bool OK(int i, int j, int a[105][105])
{
    if(i < 1 || j <1 || i > n || j > m)
        return false;
    else if(a[i][j] == -1)
        return false;
    return true;
}


void Lee(int X, int Y, int a[105][105])
{
     a[X][Y] = 1;
     bin[X][Y] = 1;
     int inceput = 1, sfarsit = 1;
     coada[inceput].l = X;
     coada[inceput].c = Y;
     coada[inceput].d = 1;
     while(inceput<=sfarsit)
     {
         x  = coada[inceput];
         inceput++;
         for(int i = 0; i < 8; ++i)
         {
             if(bin[x.l+dx[i]][x.c+dy[i]] == 0 && OK(x.l+dx[i],x.c+dy[i],a))
             {
                 a[x.l+dx[i]][x.c+dy[i]] = a[x.l][x.c] + 1;
                 y.d = x.d + 1;
                 y.l = x.l + dx[i];
                 y.c = x.c + dy[i];
                 bin[y.l][y.c] = 1;
                 sfarsit++;
                 coada[sfarsit] = y;
             }
         }
     }
}

void Read()
{
    f >> n >> m;
    f.getline(s,22);
    for(int i = 1; i <= n; ++i)
    {
        f.getline(s,200);
        for(int j = 0; j < strlen(s); ++j)
        {
            if(s[j] == 'X') jul[i][j+1] = -1, rom[i][j+1] = -1;
            else if(s[j] == 'J') xj = i, yj = j+1;
            else if(s[j] == 'R') xr = i, yr = j+1;
        }
    }
    Lee(xr,yr,rom);
    reset();
    Lee(xj,yj,jul);


}

int main()
{
    Read();
    long long minn = 10000000000, xmin, ymin;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j<=m; ++j)
        {
            if(rom[i][j] == jul[i][j] && rom[i][j]<minn && rom[i][j] > 0)
            {
                minn = rom[i][j];
                xmin = i;
                ymin = j;
            }
        }

    }
    g<<minn<<' '<<xmin<<' '<<ymin;



}

