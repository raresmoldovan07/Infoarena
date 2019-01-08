#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

ifstream f("statiuni.in");
ofstream g("statiuni.out");

vector < int > graf[100005];
int n, k, s[100005], viz[100005];

void DFS(int nod, int k1, int pre)
{
    cout << nod;
    s[nod]++;
    viz[nod] = 1;
    for(int i = 0; i < graf[nod].size(); ++i)
    {
        if( !viz[ graf[ nod ][ i ] ] && k1 <= k)
            {
                DFS(graf[ nod ][ i ], k1 + 1, nod);
                if(i > 0) s[pre]++;
            }
    }
    viz[nod] = 0;
}

int main()
{
    int x, y, k1, sol = 0;
    f >> n >> k;
    for(int i = 1; i < n; ++i)
    {
        f >> x >> y;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(graf[i].size() == 1)
        {
            k1 = 0;
            DFS(i, k1, 0);
            cout << endl;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        if(s[i] >= 2) sol++, cout << i;
    }
    g << sol << '\n';
    return 0;
}
