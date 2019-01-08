#include <iostream>
#include <fstream>
#define inf 0x3f3f3f3f
using namespace std;

ifstream f("energii.in");
ofstream g("energii.out");

int n, emax, e[1005], d[5005], w[1005];

int main()
{
    f >> n >> emax;
    for(int i = 1; i <= n; ++i) f >> e[i] >> w[i];
    for(int i = 1; i <= emax; ++i) d[i] = inf;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = emax; j >= 0; --j)
        {
            if(d[max(0, j - e[i])] != inf)
                d[j] = min(d[j], d[max(0, j - e[i])] + w[i]);
        }
    }
    if(d[emax] == inf) g << -1 << '\n';
    else g << d[emax];
}
