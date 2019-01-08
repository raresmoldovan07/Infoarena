#include <fstream>
#include <iostream>
#define INF 1000010

using namespace std;

ifstream f("subsir2.in");
ofstream g("subsir2.out");

int n, a[5005], best[5005], poz[5005], p, sol, minn[5005], min1, min2;

void Solve()
{
    for(int i = n; i >= 1; --i)
    {
        best[i] = INF; min2 = INF;
        for(int j = i + 1; j <= n; ++j)
        {
            if(a[i] <= a[j] && min2 > a[j])
            {
                min2 = a[j];
                if(best[i] > best[j] + 1)
                {
                    best[i] = best[j] + 1;
                    poz[i] = j;
                }
                else if(best[i] == best[j] + 1 && a[j] < a[poz[i]])
                {
                    poz[i] = j;
                }
            }
        }
        if(best[i] == INF) poz[i] = i, best[i] = 1;
    }
    int min2 = INF; min1 = INF; sol = INF;
    for(int i = 1; i <= n; ++i)
    {
        if(min1 > a[i])
        {
            min1 = a[i];
            if(best[i] < sol || (best[i] == sol && min2 > a[i]))
            {
                p = i;
                min2 = a[i];
                sol = best[i];
            }
        }
    }
}

void Show()
{
    g << sol << '\n';
    while(poz[p] != p)
    {
        g << p << ' ';
        p = poz[p];
    }
    g << p << '\n';
}

int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> a[i];
    Solve();
    Show();
}
