#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("vila.in");
ofstream fout("vila.out");
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
int nr,sol1,sol2,n,m,bin[200][200],a[200][200];
char x;

bool OK(int i, int j)
{
    return i >= 1 && j >=1 && i <= n && j <= m;
}

void fill(int i, int j)
{
    nr++;
    bin[i][j] = 1;
    for(int k = 0; k <= 3; ++k)
    {
        if(!bin[i+dx[k]][j+dy[k]] && OK(i+dx[k],j+dy[k]))
            fill(i+dx[k], j+dy[k]);
    }



}

void show()
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }

}


int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            fin >> x;
            if(x == '-') bin[i][j] = 0;
            else bin[i][j] = -1;
        }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(!bin[i][j])
            {
                sol1++;
                nr = 0;
                fill(i,j);
                for(int i = 1; i <= n; ++i)
                    for(int j = 1; j <= m; ++j)
                    {
                        if(bin[i][j] == 1)
                            a[i][j] = nr;
                    }
                if(nr > sol2) sol2 = nr;

            }
        }
    }
    cout<<sol1<<' '<<sol2<<endl;
    show();
}
