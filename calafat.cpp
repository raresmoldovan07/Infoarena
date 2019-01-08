#include <fstream>
#include <vector>

using namespace std;

ifstream f("calafat.in");
ofstream g("calafat.out");

const int NMax = 200005;
const int QMax = 200005;

vector < pair < int, int > > query[NMax];
pair < int, int > upd[NMax];
int n, x, q, st, dr;
long long aib[NMax], last[NMax], sol[QMax];

inline void Update(int poz, int val)
{
    while(poz <= n)
    {
        aib[poz] += val;
        poz += (poz & -poz);
    }
}

inline long long Query(int poz)
{
    long long sum = 0;
    while(poz)
    {
        sum += aib[poz];
        poz -= (poz & -poz);
    }
    return sum;
}

int main()
{
    f >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        f >> x;
        if(!last[x]) last[x] = i;
        else
        {
            upd[i] = make_pair(last[x], i - last[x]);
            last[x] = i;
        }
    }
    for(int i = 1; i <= q; ++i)
    {
        f >> st >> dr;
        query[dr].push_back(make_pair(st, i));
    }
    for(int i = 1; i <= n; ++i)
    {
        if(upd[i].first)
            Update(upd[i].first, upd[i].second);
        for(auto it : query[i])
            sol[it.second] = Query(i) - Query(it.first - 1);
    }
    for(int i = 1; i <= q; ++i)
        g << sol[i] << '\n';
}
