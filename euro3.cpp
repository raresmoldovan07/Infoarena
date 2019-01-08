#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

ifstream f("euro3.in");
ofstream g("euro3.out");

const int NMax = 4002;

int ans[2 * NMax], t, n, val, v[NMax], dp[2][NMax * 2];
int currLine, prevLine;

int main()
{
    f >> t;
    for(; t; t--)
    {
        f >> n >> val;

        for(int i = 0; i <= val; ++i)
            ans[ i ] = inf;

        for(int i = 1; i <= n; ++i)
            f >> v[ i ];

        sort(v + 1, v + n + 1);

        prevLine = 0;
        for(int i = 0; i <= val; ++i)
            dp[ prevLine ][ i ] = 0;

        for(int i = 1; i <= n; ++i)
        {
            currLine = prevLine ^ 1;
            for(int j = 0; j <= val; ++j)
                dp[ currLine ][ j ] = dp[ prevLine ][ j ];
            for(int j = 0; j <= val; ++j)
            {
                if(j - v[i] >= 0)
                {
                    dp[ currLine ][ j ] = max( dp[ currLine ][ j ], dp[ prevLine ][ j - v[i] ]);
                }
            }
            dp[ currLine ][ v[ i ] ] = v[ i ];
            for(int j = 0; j <= val; ++j)
            {
                if(dp[ currLine ][ j ])
                    ans[ j ] = min( ans[ j ], v[ i ] - dp[ currLine ][ j ]);
            }
            prevLine = currLine;
        }

        for(int i = 1; i <= val; ++i)
            if(ans[ i ] != inf)
                g << ans[ i ] << ' ';
            else g << -1 << ' ';

        g << '\n';
    }
}
