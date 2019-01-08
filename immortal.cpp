#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define NMax 22
using namespace std;

ifstream f("immortal.in");
ofstream g("immortal.out");

int n, m, use[NMax][NMax], t, gasit;
int in[NMax][NMax], a[NMax][NMax], mort[NMax];
int dx[4]= {-1,0,1,0}, dy[4] = {0,1,0,-1};
vector < pair < int, int > > v;
vector < pair < int, int > > sol;

bool OK(int x, int y, int j)
{
    int x2 = x + dx[j], y2 = y + dy[j];
    return x2>=1 && y2>=1 && x2<=n && y2<= m && a[x][y] && !a[x2][y2];
}

void Back(int k)
{
    int x, y;
    if(k == t)
    {
        gasit = 1;
        for(int i = 0; i < sol.size(); i += 2)
            g << sol[i].first << ' ' << sol[i].second << ' ' << sol[i + 1].first << ' ' << sol[i + 1].second << '\n';
    }
    else if(!gasit)
    {
        for(int j = 1; j <= t; ++j)
        {
            if(!mort[j])
            {
                x = v[j].first;
                y = v[j].second;
                sol.push_back(make_pair(x, y));
                for(int i = 0; i <= 3; ++i)
                {
                    if(OK(x + dx[i], y + dy[i], i))
                    {
                        int victima = a[x + dx[i]][y + dy[i]];
                        mort[victima] = 1;
                        a[x][y] = 0;
                        a[x + 2 * dx[i]][y + 2 * dy[i]] = j;
                        a[x + dx[i]][y + dy[i]] = 0;
                        v[j].first = x + 2 * dx[i];
                        v[j].second = y + 2 * dy[i];
                        sol.push_back(make_pair(x + 2 * dx[i], y + 2 * dy[i]));

                        Back(k + 1);

                        mort[victima] = 0;
                        a[x + dx[i]][y + dy[i]] = victima;
                        a[x][y] = j;
                        a[x + 2 * dx[i]][y + 2 * dy[i]] = 0;
                        v[j].first = x;
                        v[j].second = y;
                        sol.pop_back();
                    }
                }
                sol.pop_back();
            }
        }
    }
}

int main()
{
    int x, y;
    f >> n >> m >> t;
    v.push_back({0,0});
    for(int i = 1; i <= t; ++i)
    {
        f >> x >> y;
        a[x][y] = i;
        v.push_back(make_pair(x, y));
    }
    Back(1);

}

