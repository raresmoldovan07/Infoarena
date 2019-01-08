#include <iostream>
#include <fstream>
#include <algorithm>
#define Nmax 5005
using namespace std;

ifstream f("linterv.in");
ofstream g("linterv.out");

struct z
{
    int x, y,len;
} v[Nmax];

bool cmp(const z& b, const z& c)
{
    return b.x < c.x;
}

long long sol;
int main()
{
    int t, n, last;
    f >> t;
    for(int k = 1; k <= t; ++k)
    {
        sol = 0;
        f >> n;
        for(int i = 1; i <= n; ++i)
        {
            f >> v[i].x >> v[i].y;
            v[i].len = v[i].y - v[i].x;
        }
        sort(v+1,v+n+1,cmp);

        sol = v[1].len;
        last = v[1].y;
        for(int i = 2; i <= n; ++i)
        {
            if(v[i].x > last)
            {
                sol += v[i].len;
                last = v[i].y;
            }
            else if( v[i].y > last)
            {
                sol+= v[i].y - last;
                last = v[i].y;
            }

        }
        g  << sol << '\n';

    }

}
