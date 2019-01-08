#include <iostream>
#include <queue>
#include <fstream>
#include <algorithm>
#define NMax 505
#define inf 0x3f3f3f3f
using namespace std;

ifstream f("tort3.in");
ofstream g("tort3.out");

int n, m, k, dp[NMax][NMax], a[NMax][NMax], use[NMax][NMax];

int main()
{
    char c2;
    int lat, l = 0, c;
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            f >> c2;
            a[i][j] = c2 - '0';
        }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i - 1][j] && a[i][j] == a[i][j - 1])
            {
               dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            else dp[i][j] = 1;
        }
    }
    l = min(n, m);
    while(l > 0)
    {
        int ok = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                if(dp[i][j] >= l && !use[i][j] && !use[i - l + 1][j - l + 1] && !use[i - l + 1][j] && !use[i][j - l + 1])
                {
                    ok = 1;
                    g << l << ' ' << i << ' ' << j << '\n';
                    for(int i2 = i - l + 1; i2 <= i; ++i2)
                    {
                        for(int j2 = j - l + 1; j2 <= j; ++j2)
                            use[i2][j2] = 1;
                    }
                }
            }
        }
        l += ok;
        l--;
    }

}
