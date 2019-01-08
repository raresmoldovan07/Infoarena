#include <iostream>
#include <fstream>
#include <vector>
#define inf 0x3f3f3f3f
using namespace std;

ifstream f("hamilton.in");
ofstream g("hamilton.out");

const int NMax = 18;

int n, m, sol;
vector < int > G[NMax + 2];
int cost[NMax + 2][NMax + 2], dp[(1 << NMax) + 5][NMax + 2];

int main()
{
    f >> n >> m;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cost[i][j] = inf;

    for(int i = 1; i <= m; ++i)
    {
        int x, y;
        f >> x >> y;
        f >> cost[x][y];
        G[y].push_back(x);
    }

    for (int i = 0; i < (1 << n); ++i)
        for (int j = 0; j < n; ++j) dp[i][j] = inf;

    dp[1][0] = 0;

    for(int i = 0 ; i < (1 << n); ++i)
        for(int j = 0; j < n; ++j)
            if((1 << j) & i)
                for(int k = 0; k < G[j].size(); ++k)
                    if(i & (1 << G[ j ][ k ]))
                        dp[ i ][ j ] = min(dp[ i ][ j ], dp[ i ^ (1 << j) ][ G[ j ][ k ] ] + cost[ G[ j ][ k ] ][ j ]);

    sol = inf;
    for(int i = 0; i < G[0].size(); ++i)
        sol = min(sol, dp[(1 << n) - 1][G[0][i]] + cost[G[0][i]][0]);

    if(sol == inf) g << "Nu exista solutie";
    else g << sol << '\n';
}
