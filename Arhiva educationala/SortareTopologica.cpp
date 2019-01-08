#include <vector>
#include <fstream>
using namespace std;

ifstream f("sortaret.in");
ofstream g("sortaret.out");

int n, m, v[50005], ext[50005];
vector < int > graf[50005];

int main()
{
    int x, y;
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        f >> x >> y;
        graf[x].push_back(y);
        ext[y]++;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(!ext[i])
        {
            v[++v[0]] = i;
        }
    }
    int nod;
    for(int i = 1; i <= n; ++i)
    {
        nod = v[i];
        for(int i = 0; i < graf[nod].size(); ++i)
        {
            ext[ graf[ nod ][ i ] ]--;
            if(!ext[ graf[ nod ][ i ] ]) v[++v[0]] = graf[nod][i];
        }
    }
    for(int i = 1; i <= n; ++i) g << v[i] << ' ';
}

