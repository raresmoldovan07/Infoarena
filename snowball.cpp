#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ifstream f("snowball.in");
ofstream g("snowball.out");

const int NMax = 500005;
const int valMax = 10005;

long long n, m, v[valMax], sir[NMax], poz[valMax];
long long lungime_maxima, numar_moduri, break_point[valMax];

int main()
{
    f >> m >> n;
    for(int i = 1; i <= m; ++i)
    {
        f >> v[ i ];
        poz[ v[ i ] ] = i;
    }
    for(int i = 1; i <= n; ++i) f >> sir[ i ];
    for(int i = 1; i <= 10000; ++i) break_point[ i ] = n + 1;
    for(int i = n; i >= 1; --i)
    {
        if(sir[ i ] == v[ m ])
            break_point[ v[ m ] ] = i;
        else
            break_point[ sir[ i ]  ] = break_point[ v[ poz[ sir [ i ] ] + 1 ] ];

        lungime_maxima = max( lungime_maxima, break_point[ v[ 1 ] ] - i);
        numar_moduri += ( break_point[ v[ 1 ] ] - i );
    }
    g << lungime_maxima << ' ' << numar_moduri << '\n';
}
