#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream f("zoro.in");
ofstream g("zoro.out");
const int NMax = 1002;

struct
{
    int x, y;
}v[NMax * NMax];

int n, m, cf, dp[NMax][NMax], maxx, minn, l[NMax], c[NMax];
bool use[NMax * NMax];

int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
    {
        f >> cf;
        if(i == 1 && j == 1) maxx = cf;
        if(i == n && j == m) minn = cf;
        v[cf].x = i; v[cf].y = j;
    }
    use[maxx] = 1;
    dp[v[maxx].x][v[maxx].y] = 1;
    l[v[maxx].x] = 1;
    c[v[maxx].y] = 1;
    for(int i = maxx - 1; i >= minn; --i)
    {
        dp[v[i].x][v[i].y] = max(l[v[i].x], c[v[i].y]) + 1;
        l[v[i].x] = dp[v[i].x][v[i].y];
        c[v[i].y] = dp[v[i].x][v[i].y];
    }
    g << dp[v[minn].x][v[minn].y] << '\n';

}
