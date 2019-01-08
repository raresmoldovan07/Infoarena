#include <fstream>
#include <iostream>
#include <algorithm>
#define inf 0x3f3f3f3f
#define NM 64005
using namespace std;

ifstream f("suma4.in");
ofstream g("suma4.out");

int n, v[NM], a[60][60][60], p[NM];
int dx[4] = {0,0,1,1}, dy[4] = {0,1,0,1};

int poz(int niv, int l, int c)
{
    return niv * (niv + 1) * (2 * niv + 1)/6 + 1 + (l - 1) * (niv + 1) + (c - 1);
}


int main()
{
    int suma = 0, j = 1, sol;

    f >> n;
    for(int i = 1; i <= n; ++i) f >> v[i];
    while(suma < n)
    {
        suma += j * j;
        j++;
    }
    sol = j - 1;
    for(int i = 1; i <= sol; ++i)
    {
        for(int j = 1; j <= sol; ++j)
            a[sol][i][j] = v[poz(sol - 1, i, j)];
    }
    int minn = inf;
    for(int niv = sol - 1; niv >= 1; --niv)
    {
        for(int i = 1; i <= niv; ++i)
        {
            for(int j = 1; j <= niv; ++j)
            {
                minn = inf;
                for(int d = 0; d <= 3; ++d)
                {
                    if(a[niv + 1][i + dx[d]][j + dy[d]] < minn)
                        minn = a[niv + 1][i + dx[d]][j + dy[d]], p[poz(niv - 1, i, j)] = poz(niv,i + dx[d],j + dy[d]);
                }
                a[niv][i][j] = minn + v[poz(niv - 1, i, j)];
            }
        }
    }
    g << sol << ' ' << a[1][1][1] << '\n';
    int i = 1;
    g << "1" << ' ';
    while(p[i])
    {
        g << p[i] << ' ';
        i = p[i];
    }
}
