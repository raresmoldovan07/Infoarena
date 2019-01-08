#include <fstream>
#include <iostream>
using namespace std;

ifstream f("combinari.in");
ofstream g("combinari.out");

int x[20], n, m, k;

void show()
{
    for(int i = 1; i <= m; ++i)
        g << x[i]<< ' ';
    g << '\n';
}

void  backk(int k)
{
    if(k == m+1)
        show();
    else
    {
        for(int i = x[k-1] + 1; i <= n; ++i)
        {
            x[k] = i;
            backk(k+1);
        }
    }
}

int main()
{
    f >> n >> m;
    backk(1);

}
