#include <fstream>
#include <iostream>
#define NM 2002
using namespace std;

ifstream f("summax.in");
ofstream g("summax.out");

int n, a[NM * (NM + 1) / 2], k, b[NM * (NM + 1) / 2], st, dr;

int main()
{
    int x, y;
    f >> k;
    if(k == 1)
    {
        f >> n >> st >> dr;
        for(int i = 1; i <= n*(n+1)/2; ++i) f >> a[i];
        for(int i = (n-1)*(n-1)/2 + 1; i <= n*(n+1)/2; ++i) b[i] = 1;

        for(int i = n - 1; i >= 1; --i)
        {
            for(int j = (i - 1) * i / 2 + 1; j <= i * (i + 1) / 2; ++j)
            {
                x = i * (i + 1) / 2 + (j - ((i - 1) * i / 2 + 1) + 1);
                y = x + 1;
                if(a[x] == a[y])
                {
                    a[j] += a[x];
                    b[j] = min(2000000001, b[x] + b[y]);
                }
                else if(a[x] > a[y])
                {
                    a[j] += a[x];
                    b[j] = b[x];
                }
                else
                {
                    a[j] += a[y];
                    b[j] = b[y];
                }
            }
        }
        int k = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= i; ++j)
                cout << b[++k] << ' ';
            cout << endl;
        }
        cout << endl;
        k = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= i; ++j)
                cout << a[++k] << ' ';
            cout << endl;
        }
        if(b[1]) g << b[1] << '\n';
        else g << 2000000001;
    }
}

