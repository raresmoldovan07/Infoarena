#include <queue>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
#define NM 7505
using namespace std;

ifstream f("graf.in");
ofstream g("graf.out");

vector < int > a[NM];
queue < int > coada;
int l[NM], cost[NM], taticu[NM], nr[NM];
int n, m, st, dr;

void BFS(int nod)
{
    int nod2;
    cost[nod] = 1;
    coada.push(nod);
    while(!coada.empty())
    {
        nod2 = coada.front();
        coada.pop();
        for(int i = 0; i < l[nod2]; ++i)
        {
            if(cost[ a[nod2][i] ] == 0)
            {
                cost[a[nod2][i]] = cost[nod2] + 1;
                coada.push(a[nod2][i]);
                nr[a[nod2][i]] = nr[nod2];
                taticu[a[nod2][i]] = nod2;
            }
            else if(cost[a[nod2][i]] == cost[nod2] + 1)
            {
                nr[a[nod2][i]]++;
            }
        }


    }
    int n2, k = 0;
    n2 = dr;
    while(n2)
    {
        if(nr[n2] == nr[ taticu[ n2 ] ] && taticu[n2])
        {
            cost[++k] = taticu[n2];
        }
        n2 = taticu[n2];
    }
    cost[++k] = dr;
    sort(cost + 1, cost + k + 1);
    g << k << '\n';
    for(int i = 1; i <= k; ++i)
        g << cost[i] << ' ';
}

int main()
{
    int x, y;
    f >> n >> m >> st >> dr;
    for(int i = 1; i <= m; ++i)
    {
        f >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        l[x]++;
        l[y]++;
    }
    BFS(st);

}
