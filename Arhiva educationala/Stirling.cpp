#include <iostream>
#include <fstream>
using namespace std;

ifstream f("stirling.in");
ofstream g("stirling.out");

const int NMax = 201;
const int MOD = 98999;

int s[NMax][NMax], S[NMax][NMax];

void Precalculare_s()
{
    s[1][1] = 1;
    for(int i = 2; i < NMax; ++i)
        for(int j = 1; j <= i; ++j)
            s[i][j] = (s[i - 1][j - 1] - (i - 1) * s[i - 1][j]) % MOD;
}

void Precalculare_S()
{
    S[1][1] = 1;
    for(int i = 2; i < NMax; ++i)
        for(int j = 1; j <= i; ++j)
            S[i][j] = (S[i - 1][j - 1] + j * S[i - 1][j]) % MOD;
}

int main()
{
    int t, n, m, speta;
    Precalculare_s();
    Precalculare_S();
    f >> t;
    while(t--)
    {
        f >> speta >> n >> m;
        if(speta == 1) g << s[n][m] << '\n';
        else g << S[n][m] << '\n';
    }
}
