#include <iostream>
#include <fstream>
using namespace std;

ifstream f("inversmodular.in");
ofstream g("inversmodular.out");

long long Euler(long long n)
{
    long long ans = n;
    for(long long d = 2; d * d <= n; ++d)
    {
        if(n % d == 0)
        {
            while(n % d == 0) n /= d;
            ans /= d;
            ans *= (d - 1);
        }
    }
    if(n != 1)
    {
        ans /= n;
        ans *= (n - 1);
    }
    return ans;
}

long long Pow(long long n, long long p, long long mod)
{
    long long ans = 1;
    while(p)
    {
        if(p & 1) ans = (ans * n) % mod;
        n = (n * n) % mod;
        p >>= 1;
    }
    return ans;
}

int main()
{
    long long a, n, sol, p;
    f >> a >> n;
    p = Euler(n) - 1;
    g << Pow(a, p, n);
}
