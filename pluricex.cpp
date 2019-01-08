#include <iostream>
#include <fstream>
using namespace std;

ifstream f("pluricex.in");
ofstream g("pluricex.out");

int n,m,d;
int a[30][15], c[30];
int v[15];

void verif()
{
    for(int i = 1; i <= d; ++i)
    {
        if(v[i] == 0) return;
    }
    for(int i = 1; i <= m; ++i) g << c[i] << ' ';
    g << '\n';
}

void Backk(int k)
{
    if(k == m+1) verif();
    else
    {
        for(int i = c[k-1] + 1; i <= n; ++i)
        {
            c[k] = i;
            for(int j = 1; j <= a[i][0]; ++j) v[a[i][j]]++;
            Backk(k+1);
            for(int j = 1; j <= a[i][0]; ++j) v[a[i][j]]--;
        }
    }
}

int main()
{
    int nr;
    f >> n >> m >> d;
    for(int i = 1; i <= n; ++i)
    {
        f >> nr;
        a[i][0] = nr;
        for(int j = 1; j <= nr; ++j )
            f >> a[i][j];
    }
    Backk(1);
}
