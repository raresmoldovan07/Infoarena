#include <fstream>
#include <iostream>
#define NM 5002
#define GM 10002

using namespace std;

ifstream f("rucsac.in");
ofstream g("rucsac.out");

int N, W, w[NM], v[NM], d[3][GM];

int main()
{
    f >> N >> W;
    for(int i = 1; i <= N;++i)
        f >> w[i] >> v[i];
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 0; j <= W; ++j)
        {
            if(w[i] <= j)
            d[2][j] = max(d[1][j], d[1][j - w[i]] + v[i]);
        }
        for(int j = 0; j <= W; ++j)
            d[1][j] = d[2][j];
    }
    g << d[2][W] << '\n';
}
