#include <iostream>
#include <fstream>
#define NM 1025

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[NM], b[NM],n, m, c[NM][NM], best[NM], sol;

inline int max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> a[i];
    for(int i = 1; i <= m; ++i)
        f >> b[i];

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j]) c[i][j] = c[i-1][j-1] + 1;
            else c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    }
    sol = c[n][m];
    int indx = 0;
    for(int i = n, j = m; i && j;)
    {
        if(a[i] == b[j])
         {
             best[++indx] = a[i];
             i--; j--;
         }
        else if(c[i-1][j] > c[i][j-1])
            i--;
        else j--;

    }
    g << sol << '\n';
    for(int i = indx; i; --i)
        g << best[i] << ' ';

}
