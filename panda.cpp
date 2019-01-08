#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>
#define Nmax 502

using namespace std;

ifstream f("panda.in");
ofstream g("panda.out");

int n, m, k,s, a[Nmax][Nmax],startx, starty, nr, minn = 1000000;
bool bin[Nmax][Nmax], b[Nmax][Nmax], use[Nmax][Nmax];
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
queue < pair < int,  int > > coada;

bool lol(int x, int y)
{
    int i = s;
    while(i)
    {
        if((x%2 == 1 && y%2 == 0) || (x%2 == 0 && y%2 == 1))
        {
            x/=2;
            y/=2;
            i--;
        }
        else return false;

    }
    return true;
}

void Lee()
{
    int lin, col;
    a[startx][starty] = 1;
    use[startx][starty] = 1;
    coada.push(make_pair(startx, starty));
    while(!coada.empty())
    {
        lin = coada.front().first;
        col = coada.front().second;
        coada.pop();
        for(int i = 0; i <= 3; ++i)
        {
            if(bin[lin+dx[i]][col+dy[i]] && !use[lin+dx[i]][col+dy[i]])
            {
                use[lin+dx[i]][col+dy[i]] = 1;
                a[lin+dx[i]][col+dy[i]] = a[lin][col] + 1;
                coada.push(make_pair(lin+dx[i],col+dy[i]));
                if(b[lin+dx[i]][col+dy[i]])
                {
                    if(a[lin+dx[i]][col+dy[i]] < minn)
                    {
                        minn = a[lin+dx[i]][col+dy[i]];
                        nr = 1;
                    }
                    else if(a[lin+dx[i]][col+dy[i]] == minn)
                        nr++;
                }
            }

        }
    }
}


int main()
{
    int t,p,x,y;
    f >> p;
    f >> n >> m >> t;
    f >> startx >> starty >> k >> s;
    for(int i = 1; i <= t; ++i)
    {
        f >> x  >> y;
        b[x][y] = 1;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            f >> a[i][j];
            if(lol(a[i][j], k))
                bin[i][j] = 1, nr++;
            a[i][j] = 0;
        }

    if(p == 1)
        {
            if(bin[startx][starty])
                nr--;
            g << nr << '\n';
        }
    else
    {
        Lee();
        g << minn - 1<< ' ' << nr << '\n';
    }


}
