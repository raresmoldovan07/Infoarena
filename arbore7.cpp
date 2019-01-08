#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream f("arbore7.in");
ofstream g("arbore7.out");

const int NMax = 100005;
const int mod = 1e9 + 7;

int n, visited[NMax], dp[2][NMax], nr[2][NMax], m;
vector < int > tree[NMax];

void DFS(int father)
{
    visited[father] = 1;
    nr[0][father] = 1; nr[1][father] = 0;
    dp[0][father] = dp[1][father] = 1;
    for(auto son : tree[father])
    {
        if(!visited[son])
        {
            DFS(son);

            nr[0][father] += max(nr[0][son] - 1, nr[1][son]);
            nr[1][father] += max(nr[0][son], nr[1][son]);

            if(nr[1][son] == nr[0][son])
                dp[1][father] = (1LL * dp[1][father] * (dp[1][son] + dp[0][son])) % mod;
            else if(nr[1][son] > nr[0][son])
                dp[1][father] = (1LL * dp[1][father] * dp[1][son]) % mod;
            else dp[1][father] = (1LL * dp[1][father] * dp[0][son]) % mod;

            if(nr[1][son] == nr[0][son] - 1)
                dp[0][father] = (1LL * dp[0][father] * (dp[1][son] + dp[0][son])) % mod;
            else if(nr[1][son] > nr[0][son] - 1)
                dp[0][father] = (1LL * dp[0][father] * dp[1][son]) % mod;
            else dp[0][father] = (1LL * dp[0][father] * dp[0][son]) % mod;
        }
    }
}

void Write()
{
    g << max(nr[0][1], nr[1][1]) << ' ';
    if(nr[0][1] == nr[1][1])
        g << (dp[1][1] + dp[0][1]) % mod << '\n';
    else if(nr[0][1] > nr[1][1])
        g << dp[0][1] << '\n';
    else g << dp[1][1] << '\n';
}

int main()
{
    int x, y;
    f >> n;
    for(int i = 1; i < n; ++i)
    {
        f >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    DFS(1);
    Write();
}
