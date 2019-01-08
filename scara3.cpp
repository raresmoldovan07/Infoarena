#include <fstream>
#include <iostream>
#define INF 0x3f3f3f3f
#define NM 1205
#define cmp(a,b,c,d) ((a) < (c) || ((a) == (c) && (b) < (d)))
using namespace std;

ifstream f("scara2.in");
ofstream g("scara2.out");

int n, k,apa[NM], suc[NM], nrpasi[NM], sum[NM];

int main()
{
    int x, y;
    f >> n >> k;
    for(int i = 1; i <= n; ++i) nrpasi[i] = INF;
    nrpasi[1] = 1;
    for(int i = 1; i <= k; ++i)
    {
        f >> x >> y;
        apa[x] = y;
    }
    f >> k;
    for(int i = 1; i <= k; ++i)
    {
        f >> x >> y;
        suc[x] = y;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(i < n && cmp(nrpasi[i] + 1, sum[i], nrpasi[i + 1], sum[i + 1]))
        {
            nrpasi[i + 1] = nrpasi[i] + 1;
            sum[i + 1] = sum[i];
        }
        if(apa[i])
        {
            for(int j = 1; j <= apa[i] && i + j <= n; ++j)
            {
                if(cmp(nrpasi[i] + 1, sum[i], nrpasi[i + j], sum[i + j]))
                {
                    nrpasi[i + j] = nrpasi[i] + 1;
                    sum[i + j] = sum[i];
                }

            }
        }
        if(suc[i])
        {
            for(int j = 1;  j <= 2 * suc[i] && i + j <= n; ++j)
            {
                if(cmp(nrpasi[i] + 1, sum[i] + (j + 1)/2, nrpasi[i + j], sum [i + j]))
                {
                    nrpasi[i + j] = nrpasi[i] + 1;
                    sum[i + j] = sum[i] + (j + 1)/2;
                }
            }
        }
    }
    g << nrpasi[n] << ' ' << sum[n] << '\n';


}

