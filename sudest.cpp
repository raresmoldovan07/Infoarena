#include <fstream>
#include <queue>
#include <algorithm>
#include <iostream>
#define Nmax 120
using namespace std;

ifstream f("sudest.in");
ofstream g("sudest.out");


int n,K, a[Nmax][Nmax], p[Nmax][Nmax], c[Nmax][Nmax], maxx = -1;
short k[Nmax+Nmax];

bool OK(int x, int y)
{
    return x <= n && y <= n;
}

void Read()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            f >> a[i][j];
    f >> K;
    for(int i = 1; i <= K; ++i)
        f >> k[i];
}

void sol(int x,int y, int pas)
{
    bool gasit = 0;
    if(x == 1 && y == 1)
        g << x << ' ' << y << '\n';
    else
    {
        if(c[x][y] == a[x][y] + c[x][y-k[pas]])
        {
            gasit = 1;
            sol(x,y-k[pas],pas-1);
            g << x << ' ' << y << '\n';
        }
        if(!gasit && c[x][y] == a[x][y] + c[x-k[pas]][y])
        {
            sol(x-k[pas],y,pas-1);
            g << x << ' ' << y << '\n';
        }
    }
}


void Solve()
{
    int pas = 1;
    c[1][1] = a[1][1];
    p[1][1] = 1;
    for(int l = 1; l <= K; ++l)
    {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
            {
                if(p[i][j] == l)
                {
                    if(OK(i, j+k[l]) && c[i][j] + a[i][j+k[l]] > c[i][j+k[l]]) // EST
                    {
                        c[i][j+k[l]] = c[i][j] + a[i][j+k[l]];
                        p[i][j+k[l]] = l+1;
                    }
                    if(OK(i+k[l], j) && c[i][j] + a[i+k[l]][j] > c[i+k[l]][j]) // SUD
                    {
                        c[i+k[l]][j] = c[i][j] + a[i+k[l]][j];
                        p[i+k[l]][j] = l+1;
                    }
                }
            }
    }
    g << c[n][n] << '\n';
    sol(n,n,K);
}

int main()
{
    Read();
    Solve();
}
