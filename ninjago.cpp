#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#define NM 31205
using namespace std;

ifstream f("ninjago.in");
ofstream g("ninjago.out");

int n, m, p;
vector < int > v[NM];
int x[NM], sol, y[NM], indx[NM], e[NM], c[NM], viz[NM], rang[NM], gr[NM];

bool cmp(const int& a, const int& b)
{
    if(e[a] == e[b]) return c[a] < c[b];
    return e[a] < e[b];
}

void DFS(int nod)
{
    sol++;
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        if(!viz[v[nod][i]]) DFS(v[nod][i]);
    }
}

void Union(int a, int b)
{
    if(rang[a] > rang[b]) gr[b] = a;
    else gr[a] = b;
    if(rang[a] == rang[b]) rang[b]++;
}

int Find(int a)
{
    int a2 = a, aux;
    while(a != gr[a]) a = gr[a];
    while(a2 != a)
    {
        aux = gr[a2];
        gr[a2] = a;
        a2 = aux;
    }
    return a;
}

int main()
{
    f >> p;
    if(p == 1)
    {
        char c;
        int ok, x1, y1;
        f >> n >> m;
        for(int i = 1; i <= m; ++i)
        {
            ok = 1;
            f >> x1 >> y1;
            for(int j = 1; j <= 4; ++j)
            {
                f >> c;
                if(c == 'E')
                {
                    ok = 0;
                }
            }
            if(ok)
            {
                v[x1].push_back(y1);
                v[y1].push_back(x1);
            }
        }
        DFS(1);
        g << sol << '\n';
    }
    else
    {
        int produs, cost, sole = 0, nr = 0;
        long long sol = 0;
        char C;
        f >> n >> m;
        for(int i = 1; i <= m; ++i)
        {
            produs = 1;
            cost = 0;
            f >> x[i] >> y[i];
            indx[i] = i;
            for(int j = 1; j <= 4; ++j)
            {
                f >> C;
                if(C != 'E')
                {
                    cost += (produs * (int)(C - 64));
                }
                else e[i]++;
                produs *= 5;
            }
            c[i] = cost;
        }
        for(int i = 1; i <= n; ++i) rang[i] = 1, gr[i] = i;
        if(p == 2)
        {
            sort(indx + 1, indx + m + 1, cmp);
            for(int i = 1; i <= m; ++i)
            {
                if(Find( x[ indx[ i ] ] ) != Find( y[ indx[ i ] ] ))
                {
                    sol += c[ indx[ i ] ];
                    sole += e[ indx[ i ] ];
                    if(e[ indx[ i ] ]) nr++;
                    Union(Find( x[ indx[ i ] ]), Find(y[ indx[ i ] ]));
                }
            }
            g << nr << '\n' << sole << '\n';
        }
        else
        {
            sort(indx + 1, indx + m + 1, cmp);
            for(int i = 1; i <= m; ++i)
            {
                if(Find( x[ indx[ i ] ] ) != Find( y[ indx[ i ] ] ))
                {
                    sol += c[ indx[ i ] ];
                    sole += e[ indx[ i ] ];
                    if(e[ indx[ i ] ]) nr++;
                    Union(Find( x[ indx[ i ] ]), Find(y[ indx[ i ] ]));
                }
            }
            g << sol << '\n';
        }
    }
}
