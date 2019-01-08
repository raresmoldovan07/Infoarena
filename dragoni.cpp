#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

ifstream f("dragoni.in");
ofstream g("dragoni.out");

const int NMax = 805;

int n, m, dmaxx, t, use[NMax][NMax];
vector < pair < int, int > > graf[NMax];
priority_queue < pair < int, pair < int, int > >, vector < pair < int, pair < int, int > > >, greater < pair < int, pair < int, int > > > > q;
int c[NMax], d[NMax], visited[NMax], dp[NMax][NMax];

void DFS(int node)
{
    visited[node] = 1;
    dmaxx = max(dmaxx, d[node]);
    for(auto it : graf[node])
        if(!visited[it.first] && it.second <= d[ 1 ])
            DFS(it.first);
}

void Dijkstra()
{
    int dragon, node, drum;
    q.push({0, {1, 1}});
    dp[1][1] = 0;
    while( !q.empty() )
    {
        drum = q.top().first;
        node = q.top().second.first;
        dragon = q.top().second.second;
        q.pop();
        if(!use[node][dragon])
        {
            use[node][dragon] = 1;
            for(auto it : graf[node])
            {
                if(d[ dragon ] >= it.second)
                {
                    if(dp[it.first][dragon] >= dp[node][dragon] + it.second)
                    {
                        dp[it.first][dragon] = dp[node][dragon] + it.second;
                        if(d[ dragon ] < d[ it.first ])
                        {
                            dp[it.first][it.first] = min(dp[it.first][it.first], dp[it.first][dragon]);
                            q.push({dp[it.first][dragon], {it.first, it.first}});
                        }
                        else
                        {
                            q.push({dp[it.first][dragon], {it.first, dragon}});
                        }
                        //cout << node << ' ' << it.first << dp[it.first][dragon] << '\n';
                    }
                }
            }
        }
    }
}

int main()
{
    int x, y, cost;
    f >> t >> n >> m;
    for(int i = 1; i <= n; ++i) f >> d[i];
    for(int i = 1; i <= m; ++i)
    {
        f >> x >> y >> cost;
        graf[x].push_back({y, cost});
        graf[y].push_back({x, cost});
    }
    if(t == 1)
    {
        DFS(1);
        g << dmaxx << '\n';
    }
    else
    {
        int solmin = 0x3f3f3f3f;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                dp[i][j] = 0x3f3f3f3f;
        Dijkstra();
        for(int i = 1; i <= n - 1; ++i)
            solmin = min(solmin, dp[n][i]);
        g << solmin << '\n';
    }

}
