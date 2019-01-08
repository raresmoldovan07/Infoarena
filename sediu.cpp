#include <iostream>
#include <fstream>
using namespace std;

ifstream f("diamant.in");
ofstream g("diamant.out");

const int MOD = 10000;
const int ZERO = 44100;

int dp[2][1 << 18], n, m, x;

int main()
{
    f >> n >> m >> x;
    int l = 1, sum = 1;
    dp[0][ZERO] = dp[0][ZERO + 1] = dp[0][ZERO - 1] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(i == 1 && j == 1) continue;

            sum += i * j;
            for(int k = -ZERO; k <= ZERO; ++k)
            {
                dp[l][ZERO + k] = dp[!l][ZERO + k] + dp[!l][ZERO - i * j + k] + dp[!l][ZERO + i * j + k];
                dp[l][ZERO + k] %= MOD;
            }
            l = !l;
        }
    if(x < 0) x = -x;
    if(x > sum) g << 0 << '\n';
    else g << dp[!l][ZERO + x] << '\n';
}
