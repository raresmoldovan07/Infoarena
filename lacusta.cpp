#include <iostream>
#include <fstream>
#define NM 253
#define inf 0x3f3f3f3f
using namespace std;

ifstream f("lacusta.in");
ofstream g("lacusta.out");

unsigned short int n,m,  a[NM][NM];
unsigned long long d[2][NM];

int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        f >> a[i][j];
    d[1][1] = inf;
    for(int i = 2; i <= m; ++i) d[1][i] = a[1][1] + a[1][i] + a[2][i];
    int jmin, min1, min2;
    for(int i = 2; i < n; ++i)
    {
        if(d[1][1] <= d[1][2])
        {
            min1 = d[1][1];
            min2 = d[1][2];
            jmin = 1;
        }
        else
        {
            min1 = d[1][2];
            min2 = d[1][1];
            jmin = 2;
        }
        for(int j = 3; j <= m; ++j)
        {
            if(d[1][j] < min1)
            {
                min2 = min1;
                min1 = d[1][j];
                jmin = j;
            }
            else if(d[1][j] < min2) min2 = d[1][j];
        }
        for(int j = 1; j <= m; ++j)
        {
            if(j != jmin)
            {
                d[1][j] = min1 + a[i][j] + a[i + 1][j];
            }
            else d[1][j] = min2 + a[i][j] + a[i + 1][j];
        }

    }
    min1 = d[1][1];
    for(int j = 2; j <= m; ++j)
    {
        if(d[1][j] < min1) min1 = d[1][j];
    }
    g << min1 + a[n][m] << '\n';
    return 0;
}
