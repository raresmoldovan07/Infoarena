#include <iostream>
#include <fstream>
#define inf 0x3f3f3f3f
#define NM 5005
using namespace std;

ifstream f("joc15.in");
ofstream g("joc15.out");

int n,  k, maxx;

int main()
{
    int s ,d[3][NM], a[3][NM];
    f >> n >> k;
    for(int i = 1; i <= 2; ++i)
        for(int j = 1; j <= n; ++j)
            f >> a[i][j];
    d[1][1] = a[1][1];
    d[2][1] = 0;
    for(int j = 2; j <= n; ++j)
    {
        for(int i = 1; i <= 2; ++i)
        {
            maxx = -inf;
            s = a[i][j];
            for(int j1 = 1; j1 < k && j1 < j; ++j1)
            {
                s += a[i][j - j1];
                if(s + d[3 - i][j - j1] > maxx) maxx = s + d[3 - i][j - j1];
            }
            d[i][j] = maxx;
        }
    }
    if(d[1][n] + a[2][n] > d[2][n]) d[2][n] = d[1][n] + a[2][n];
    g << d[2][n] << '\n';

}


