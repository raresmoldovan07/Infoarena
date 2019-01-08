#include <fstream>
#include <iostream>
#include <vector>
#define MOD 1999999973
using namespace std;

ifstream f("elmaj.in");
ofstream g("elmaj.out");

int a[1000005], ap;

int main()
{
    int n, elmaj;
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        f >> a[i];
        if(ap == 0)
        {
            elmaj = a[i];
            ap++;
        }
        else if(elmaj == a[i]) ap++;
        else ap--;
    }
    ap = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(elmaj == a[i]) ap++;
    }
    g << elmaj << ' ' << ap << '\n';

}
