#include <fstream>
#include <iostream>
#include <vector>
#define NM 105
#define MOD 30011
using namespace std;

ifstream f("iepuri2.in");
ofstream g("iepuri2.out");

int n, m, d[NM][NM], rad, fii[NM],k;
vector < int > arb[NM];

void Solve(int nod)
{
    for(int i = 0; i < arb[nod].size(); ++i) Solve(arb[nod][i]);
    for(int i = k; i; --i)
    {
        d[nod][i] = 1;

        for(int j = 0; j < arb[nod].size(); ++j)
        {
              d[arb[nod][j]][i + 1] += d[arb[nod][j]][i + 2];
              d[arb[nod][j]][i + 1] %= MOD;
              long long produs = d[nod][i];
              produs *= d[arb[nod][j]][i + 1];
              d[nod][i] = produs % MOD;
        }

    }
}

void Write()
{
    int sol = 0;
    for(int i = 1; i <= k; ++i)
    {
        sol = (sol + d[rad][i])%MOD;
    }
    g << sol << '\n';

}

int main()
{
    int a,b;
    f >> n >> k;
    for(int i = 1; i < n; ++i)
    {
        f >> a >> b;
        arb[a].push_back(b);
        fii[b] = a;
    }
    for(int i = 1; i <= n; ++i)
        if(!fii[i]) rad = i;
    Solve(rad);
    Write();
}
