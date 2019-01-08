#include <bits/stdc++.h>
using namespace std;

ifstream f("ramen.in");
ofstream g("ramen.out");

const int NMax = 100001;

int p[NMax], t[NMax], n, d, sol[NMax];

struct compare
{
    bool operator() (const int& a, const int& b) const
    {
        if(p[ a ] == p[ b ]) return t[ a ] < t[ b ];
        return p[ a ] < p[ b ];
    }
};

set < int > times;
set < int, compare > order;

int main()
{
    f >> n >> d;
    for(int i = 1; i <= n; ++i)
    {
        f >> t[ i ] >> p[ i ];
        order.insert( i );
        times.insert( t[ i ] );
    }
    for(auto it : order)
    {
        set < int > :: iterator IT = times.lower_bound(t[it] - p[it] - d);
        sol[it] = *IT + p[it] + d;
        times.erase(IT);
    }
    for(int i = 1; i <= n; ++i) g << sol[i] << '\n';
}
