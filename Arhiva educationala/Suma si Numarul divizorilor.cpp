#include <iostream>
#include <fstream>
#define mod 9973
#define NM 1000005
using namespace std;

ifstream f("ssnd.in");
ofstream g("ssnd.out");

long long n;
int t, d[NM], k;
bool viz[NM];

void ciuru()
{
    for(int i = 2; i < NM; ++i)
    {
        if(!viz[i])
        {
            d[++k] = i;
            for(int j = i + i; j < NM; j += i) viz[j] = 1;
        }
    }
}

inline long long pow(int x, int p)
{
    long long ans = 1;
    x %= mod;
    while(p)
    {
        if(p % 2) ans = (ans * x) % mod;
        x = (x * x) % mod;
        p >>= 1;
    }
    return ans;
}

int main()
{
    long long nrd, sum;
    f >> t;
    ciuru();
    for(int j = 1; j <= t; ++j)
    {
        nrd = 1; sum = 1;
        f >> n;
        for(int i = 1; i <= k && d[i] * d[i] <= n; ++i)
        {
            if(n % d[i]) continue;
            int p = 0;
            long long top, bot;

            while(n % d[i] == 0)
            {
                n /= d[i];
                p++;
            }
            nrd *= (p + 1);
            top = (pow(d[i], (p + 1)) - 1) % mod;
            bot = pow(d[i] - 1, mod - 2) % mod;
            sum = (((sum * top) % mod) * bot) % mod;
        }
        if(n != 1)
        {
            nrd *= 2;
            sum = sum * (n + 1) % mod;
        }
        g << nrd << ' ' << sum << '\n';
    }
}
