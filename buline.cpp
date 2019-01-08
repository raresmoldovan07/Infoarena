#include <fstream>
#include <iostream>
#include <algorithm>
#define Nmax 200002
using namespace std;

ifstream f("buline.in");
ofstream g("buline.out");

long long int v[Nmax+Nmax], Smax = -400000000;
int bin[2] = {-1,1};

int main()
{
    int n, x,m;
    f >> n;
    m = n;

    for(int i = 1; i <= n; ++i)
    {
        f >> v[i] >> x;
        v[i] *= bin[x];
    }
    for(int i = 1; i <= n-1; ++i)
        v[n+i] = v[i];
    n = n+n-1;


    int beg, minn = 0, end, last, len = 200005, begm  = 200005;
    for(int i = 1; i <= n; ++i)
    {

        v[i] = v[i] + v[i-1];

        if(v[i]-minn > Smax)
        {
            Smax = v[i] - minn;
            beg = last+1;
            end = i;
            len = end-beg+1;

        }
        else if(v[i]-minn  == Smax && i-last > len)
        {
            len = i-last;
            beg = last+1;
            end = i;
        }
        if(v[i] < minn)
        {
            minn = v[i];
            last = i;
        }
    }

    g << Smax << ' ' ;
    if(beg > m)
        g << beg-m << ' ' << len;
    else g << beg << ' ' << len;
    g << '\n';


}
