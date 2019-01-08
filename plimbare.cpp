#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

ifstream f("plimbare.in");
ofstream g("plimbare.out");

int n, postordine[105], k, maxx, v[105], c[105];
int use[105],  where[105], comp;
vector < int > G[105];
vector < int > GT[105];

void DFS(int nod)
{
    use[nod] = 1;
    for(int i = 0; i < G[nod].size(); ++i)
    {
        if(!use[G[nod][i]]) DFS(G[nod][i]);
    }
    postordine[++k] = nod;
}

void DFST(int nod)
{
    where[nod] = comp;
    c[++k] = nod;
    for(int i = 0; i < GT[nod].size(); ++i)
    {
        if(!where[GT[nod][i]]) DFST(GT[nod][i]);
    }
}


int main()
{
    int x,y,m;
    f >> n >> m;
    for(int i = 1; i <= n*(n-1)/2; ++i)
    {
        f >> x >> y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(!use[i]) DFS(i);
    }
    for(int i = n; i >= 1; --i)
    {
        if(!where[postordine[i]])
        {
            comp++;
            k = 0;
            DFST(postordine[i]);
        }
        if(k > maxx)
        {
            maxx = k;
            for(int j = 1; j <= k; ++j) v[j] = c[j];
        }
    }
    for(int i = 1; i <= k; ++i)
    {
        prez = v[i];
        Back(v[i]);
    }
}
