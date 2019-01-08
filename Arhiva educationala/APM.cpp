#include <queue>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
#define NM 400005
using namespace std;

ifstream f("apm.in");
ofstream g("apm.out");

vector < int > sol;
struct muchie
{
    int x, y, c;
};
muchie arb[NM];
int cost, n, gr[NM], ind[NM], r[NM], m;

bool cmp(const int& i, const int& j)
{
    return arb[ i ].c < arb[ j ].c;
}

int Find(int x)
{
    int y = x, aux;
    for(;x != gr[x]; x = gr[x]);
    for(;y != gr[y];)
    {
        aux = gr[y];
        gr[y] = x;
        y = gr[y];
    }
    return x;
}

void Union(int i, int j)
{
    if(r[i] > r[j]) gr[j] = i;
    else gr[i] = j;
    if(r[i] == r[j]) r[j]++;
}

int main()
{
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        f >> arb[ i ].x >> arb[ i ].y >> arb[ i ].c;
        ind[ i ] = i;
    }
    for(int i = 1; i <= n; ++i) gr[ i ] = i, r[ i ] = 1;
    sort(ind + 1, ind + m + 1, cmp);
    for(int i = 1; i <= m; ++i)
    {
        if(Find( arb[ ind[ i ] ].x ) != Find( arb[ ind[ i ] ].y ))
        {
            cost += arb[ ind[ i ] ].c;
            Union( Find(arb[ ind[ i ] ].x), Find(arb[ ind[ i ] ].y ));
            sol.push_back(ind[i]);
        }
    }
    g << cost << '\n' << n - 1 << '\n';
    for(int i = 0; i < sol.size(); ++i)
        g << arb[ sol[ i ] ].x << ' ' << arb[ sol[ i ] ].y << '\n';
}
