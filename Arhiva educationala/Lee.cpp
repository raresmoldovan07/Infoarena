#include  <iostream>
#include  <fstream>
#include  <queue>
using namespace std;

ifstream fin("alee.in");
ofstream fout("alee.out");

int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};

int n, m, a[200][200];
int startx, starty, stopx, stopy;
queue < pair < int, int > > coada;

void Read()
{
    fin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int x, y;
        fin >> x >> y;
        a[x][y] = -1;
    }
    fin >> startx >> starty;
    fin >> stopx >>stopy;
}

bool OK(int i, int j)
{
    if( i < 1 || j < 1 || i > n || j > n )
        return false;
    if(a[i][j] == -1)
        return false;
    return true;
}

void Lee()
{
    int i, j, nexti, nextj;
    a[startx][starty] = 1;
    coada.push(make_pair(startx, starty));
    while ( !coada.empty() )
    {
        i =  coada.front().first;
        j =  coada.front().second;

        coada.pop();
        for(int directie = 0; directie < 4; ++directie)
        {
            nexti = i + di[directie];
            nextj = j + dj[directie];
            if(OK(nexti,nextj) && a[nexti][nextj] == 0)
               {
                   a[nexti][nextj] = a[i][j] + 1;
                   coada.push(make_pair(nexti,nextj));
               }
        }
    }
}

int main()
{
    Read();
    Lee();
    fout << a[stopx][stopy] << endl;



}
