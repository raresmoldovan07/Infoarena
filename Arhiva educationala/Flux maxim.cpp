#include <bits/stdc++.h>
using namespace std;

ifstream f("maxflow.in");
ofstream g("maxflow.out");

const int NMax = 1005;

int n, m;
vector < int > G[NMax];
vector < int > :: iterator it;
int cost[NMax][NMax], flow[NMax][NMax], daddy[NMax];
int source, sink, flux;

inline int BFS()
{
    int ok = 0;
    queue < int > q;
    memset(daddy, 0, sizeof(daddy));
    daddy[source] = -1;
    q.push(source);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(it = G[node].begin(); it != G[node].end(); ++it)
        {
            if(daddy[ *it ] == 0 && cost[node][ *it ] > flow[node][ *it ])
            {
                if(*it != sink)
                {
                    q.push(*it);
                    daddy[*it] = node;
                }
                else ok = 1;
            }
        }
    }
    return ok;
}

inline void Solve()
{
    int path = BFS();
    while( path )
    {
        for(it = G[sink].begin(); it != G[sink].end(); ++it)
        {
            if(daddy[ *it ] && cost[ *it ][ sink ] > flow[ *it ][ sink ])
            {
                int minn = 0x3f3f3f3f;
                daddy[ sink ] = *it;
                for(int node = sink; node != source; node = daddy[ node ])
                        if(minn > cost[daddy[node]][node] - flow[daddy[node]][node])
                            minn = cost[daddy[node]][node] - flow[daddy[node]][node];

                if(minn <= 0) continue;

                flux += minn;
                for(int node = sink; node != source; node = daddy[node])
                    {
                        flow[node][daddy[node]] -= minn;
                        flow[daddy[node]][node] += minn;
                    }
            }
        }
        path = BFS();
    }
}

int main()
{
    int x, y, z;
    f >> n >> m;
    source = 1; sink = n;
    for(int i = 1; i <= m; ++i)
    {
        f >> x >> y >> z;
        cost[ x ][ y ] += z;
        G[ x ].push_back(y);
        G[ y ].push_back(x);
    }
    Solve();
    g << flux;
}
