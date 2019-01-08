#include <fstream>
#include <vector>
#include <iostream>
#include <queue>
#define inf 0x3f3f3f3f
#define NM 100005
using namespace std;

ifstream f("darb.in");
ofstream g("darb.out");

vector < int > arb[NM];
queue < int > q;
int n, c[NM], viz[NM], last, diametru;

void BFS(int start)
{
    for(int i = 1; i <= n; ++i) viz[i] = 0;
    int nod;
    q.push(start);
    viz[start] = 1;
    c[start] = 1;
    while(!q.empty())
    {
        nod = q.front();
        q.pop();
        for(int i = 0 ; i < arb[nod].size(); ++i)
        {
            if(!viz[arb[nod][i]])
            {
                q.push(arb[nod][i]);
                c[arb[nod][i]] = c[nod] + 1;
                viz[arb[nod][i]] = 1;
                diametru = c[arb[nod][i]];
                last = arb[nod][i];

            }
        }
    }
}

int main()
{
    int x, y;
    f >> n;
    for(int i = 1; i <= n - 1; ++i)
    {
        f >> x >> y;
        arb[x].push_back(y);
        arb[y].push_back(x);
    }
    BFS(1);
    BFS(last);
    g << diametru << '\n';
}
