#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream f("turn.in");
ofstream g("turn.out");

int n, h, st[20], use[20], l[20], c[20];

void Back(int k, int h2)
{
    if(h2 == h)
    {
        for(int i = 1; i < k; ++i)
            g << st[i] << ' ';
        g << '\n';
    }
    else
    {
        for(int i = 1; i <= n; ++i)
        {
            if(!use[i])
                if(h2 + l[i] <= h && c[st[k-1]] != c[i] && l[st[k - 1]] >= l[i])
                {
                    st[k] = i;
                    use[i] = 1;
                    Back(k + 1, h2 + l[i]);
                    use[i] = 0;
                }
        }
    }
}

int main()
{
    f >> n >> h;
    for(int i = 1; i <= n; ++i) f >> l[i] >> c[i];
    l[0] = 100000;
    Back(1, 0);
}
