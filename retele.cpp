
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream f("retele.in");
ofstream g("retele.out");

const int NMax = 50005;

vector < int > graf[NMax], graft[NMax];
vector < int > sol[NMax];
vector < int > toposort;
int n, m, networks, visited[NMax], where[NMax];

void DFS(int node)
{
    visited[node] = 1;
    for(auto it : graf[node])
        if(visited[it] == 0)
            DFS(it);
    toposort.push_back(node);
}

void DFST(int node)
{
    visited[node] = 1;
    where[node] = networks;
    for(auto it : graft[node])
        if(!visited[it])
            DFST(it);
}

int main()
{
    int x, y;
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        f >> x >> y;
        graf[x].push_back(y);
        graft[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(!visited[ i ])
            DFS( i );
    }
    for(int i = 1; i <= n; ++i) visited[i] = 0;
    for(int i = toposort.size() - 1; i >= 0; --i)
    {
        if(!visited[ toposort[ i ] ])
        {
            networks++;
            DFST(toposort[ i ]);
        }
    }
    for(int i = 1; i <= n; ++i)
        sol[where[i]].push_back(i);
    sort(sol + 1, sol + networks + 1);
    g << networks << '\n';
    for(int i = 1; i <= networks; ++i)
    {
        g << sol[i].size() << ' ';
        for(auto it : sol[i])
            g << it << ' ';
        g << '\n';
    }
}
