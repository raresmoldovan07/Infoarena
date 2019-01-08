#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

int a[105][105], b[105][105], S, n;
queue < pair <int, int> > coada;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0,1,0,-1};

bool OK(int i, int j)
{
    return i >= 1 && j >= 1 && i <= n && j <= n;
}
void Lee()
{
    int i, j, xnou, ynou;
    b[1][1] = a[1][1];
    coada.push(make_pair(1,1));
    while(!coada.empty())
    {
        i = coada.front().first;
        j = coada.front().second;
        coada.pop();
        for(int k = 0; k < 4; ++k)
        {
            xnou = i + dx[k];
            ynou = j + dy[k];
            if(a[xnou][ynou] + b[i][j] < b[xnou][ynou] && OK(xnou,ynou))
            {
                b[xnou][ynou] = a[xnou][ynou] + b[i][j];
                coada.push(make_pair(xnou,ynou));
            }
        }
    }
}
int main()
{
    ifstream f("taxe2.in");
    ofstream g("taxe2.out");
    f >> S >> n;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        f >> a[i][j],
        b[i][j] = 100000;
    }
    Lee();
    cout<<b[n][n];
    if(S >= b[n][n]) g << S - b[n][n];
    else g << "-1";
}
