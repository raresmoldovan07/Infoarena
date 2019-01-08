#include <iostream>
#include <queue>
#include <fstream>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

ifstream f("lanterna.in");
ofstream g("lanterna.out");

int n,m,  K,t[52][52], w[52][52], tmin[52][1002], prieten[52], used[52][1002];
vector < int > graf[52];
queue <pair < int, int > > q;

int minT(int kmax)
{
    int nod, k, sol = INF, consum, nod2;
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= kmax; ++j)
            tmin[i][j] = INF;
    q.push(make_pair(1, 0));
    tmin[1][0] = 0;
    while(!q.empty())
    {
        k = q.front().second;
        nod = q.front().first;
        q.pop();
        if(tmin[nod][k] < sol)
            for(int i = 0; i < graf[nod].size(); ++i)
            {
                nod2 = graf[nod][i];
                if(k + w[nod][nod2] <= kmax)
                {
                    consum = k + w[nod][nod2];
                    if(prieten[nod2]) consum = 0;
                    if(tmin[nod][k] + t[nod][nod2] < tmin[nod2][consum])
                    {
                        tmin[nod2][consum] = tmin[nod][k] + t[nod][nod2];
                        if(nod2 == n && sol > tmin[nod2][consum]) sol = tmin[nod2][consum];
                        if(!used[nod2][consum] && sol > tmin[nod2][consum]) q.push(make_pair(nod2, consum)), used[nod2][consum] = 1;
                    }
                }
            }
        used[nod][k] = 0;
    }
    return sol;


}

int main()
{
    int mintimp, st, dr, mink, x, y, kmin;
    f >> n >> K;
    for(int i = 1; i <= n; ++i) f >> prieten[i];
    f >> m;
    for(int i = 1; i <= m; ++i)
    {
        f >> x >> y;
        graf[x].push_back(y);
        graf[y].push_back(x);
        f >> t[x][y] >> w[x][y];
        t[y][x] = t[x][y];
        w[y][x] = w[x][y];
    }
    mintimp = minT(K);
    kmin = K;
    st = 1;
    dr = K - 1;
    while(st <= dr)
    {
        m = (st + dr) >> 1;
        if(minT(m) == mintimp)
        {
            kmin = m;
            dr = m - 1;
        }
        else st = m + 1;
    }
    g << mintimp << ' ' << kmin << '\n';

}
