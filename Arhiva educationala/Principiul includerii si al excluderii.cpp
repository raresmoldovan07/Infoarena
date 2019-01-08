#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#define NM 1000000
using namespace std;

ifstream f("pinex.in");
ofstream g("pinex.out");

int prim[80000], fact[80000];
bool use[NM];
long long a, b, n;

void ciur()
{
    for(int i = 2; i < NM; ++i)
    {
        if(!use[ i ])
        {
            prim[ ++prim[ 0 ] ] = i;
            for(int j = i + i; j < NM; j += i)
                use[j] = true;
        }
    }
}

void Solve(long long a, long long b)
{
    int d = 0;
    fact[0] = 0;
    while(b > 1)
    {
        d++;
        if(b % prim[d] == 0)
        {
            fact[ ++fact[ 0 ] ] = prim[d];
            while(b % prim[d] == 0) b /= prim[d];
        }
        if(prim[d] > sqrt(b) && b > 1)
        {
            fact[++fact[0]] = b;
            b = 1;
        }
    }

    long long prod = 1, counter, sol = a;

    for(int i = 1; i < (1 << fact[0]); ++i)
    {
        prod = 1;
        counter = 0;
        for(int j = 0; j < fact[0]; ++j)
        {
            if((1 << j) & i)
            {
                prod = 1LL * prod * fact[j + 1];
                counter++;
            }
        }
        if(counter % 2) counter = -1;
        else counter = 1;

        sol = sol + 1LL * counter * (a / prod);
    }

    g << sol << '\n';
}

int main()
{
    ciur();
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        f >> a >> b;
        Solve(a, b);
    }
    return 0;
}
