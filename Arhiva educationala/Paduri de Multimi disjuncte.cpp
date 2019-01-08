#include <fstream>
using namespace std;

ifstream f("disjoint.in");
ofstream g("disjoint.out");

int n, m, rang[100005], tata[100005];

int Find(int x)
{
    int rad = x, y;
    while(tata[rad] != rad)
    {
        rad = tata[rad];
    }
    while(tata[x] != x)
    {
        y = tata[x];
        tata[x] = rad;
        x = y;
    }
    return rad;
}

void Union(int x, int y)
{
    if(rang[x] > rang[y])
        tata[y] = x;
    else tata[x] = y;

    if(rang[x] == rang[y]) rang[y]++;
}



int main()
{
    int x, y, query;
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        rang[i] = 1;
        tata[i] = i;
    }
    for(int j = 1; j <= m; ++j)
    {
        f >> query >> x >> y;
        if(query == 2)
        {
            if(Find(x) == Find(y)) g << "DA" << '\n';
            else g << "NU" << '\n';
        }
        else
        {
            Union(Find(x), Find(y));
        }
    }
}
