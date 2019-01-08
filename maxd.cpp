#include <fstream>
#include <iostream>
#define NM 5005
using namespace std;

ifstream f("maxd.in");
ofstream g("maxd.out");

int d[NM], use[45005], minn, nr, nrd, maxx;

inline void ciur(int &k)
{
    for(int i = 2; i <= 45000; ++i)
    {
        if(!use[i])
        {
            d[++k] = i;
            for(int j = i + i; j <= 45000; j += i)
                use[j] = 1;
        }
    }
}

int main()
{
    int a, b, k = 0;
    f >> a >> b;
    ciur(k);
    for(int i = a; i <= b; ++i)
    {
        int n = i, p = 0, prod = 1;
        for(int j = 1; j <= k && d[j] * d[j] <= n; ++j)
        {
            if(n % d[j]) continue;
            p = 0;
            while(n % d[j] == 0)
            {
                p++;
                n /= d[j];
            }
            prod *= (p + 1);
        }
        if(n != 1) prod *= 2;
        if(prod > nrd)
        {
            minn = i;
            nrd = prod;
            nr = 1;
        }
        else if(prod == nrd) nr++;
    }
    g << minn << ' ' << nrd << ' ' << nr << '\n';
}
