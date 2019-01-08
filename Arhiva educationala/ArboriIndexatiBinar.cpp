#include <fstream>
#define zero(x) ((x ^(x-1)) & x)
#define NM 100005
using namespace std;

ifstream f("aib.in");
ofstream g("aib.out");
int n, m, aib[NM];

void Update(int val, int poz)
{
    while(poz <= n)
    {
        aib[poz] += val;
        poz += zero(poz);
    }
}

int Sum(int poz)
{
    int s = 0;
    while(poz > 0)
    {
        s += aib[poz];
        poz -= zero(poz);
    }
    return s;
}

int Search(int s)
{
    int st = 1, dr = n + 1, poz = n + 1, m, S;
    S = Sum(n);
    if(S == s) return n;
    while(st <= dr)
    {
        m = (st + dr) >> 1;
        S = Sum(m);
        if(s < S)
        {
            dr = m - 1;
        }
        else if(s == S)
        {
            poz = min(poz, m);
            dr = m - 1;
        }
        else if(s > S)
        {
            st = m + 1;
        }
    }
    if(poz == n + 1) return -1;
    return poz;
}

int main()
{
    int x, query, a, b;
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        f >> x;
        Update(x, i);
    }
    for(int i = 1; i <= m; ++i)
    {
        f >> query;
        if(query <= 1)
        {
            f >> a >> b;
            if(query == 0) Update(b, a);
            else g << Sum(b) - Sum(a - 1) << '\n';
        }
        else
        {
            f >> a;
            g << Search(a) << '\n';
        }

    }
}
