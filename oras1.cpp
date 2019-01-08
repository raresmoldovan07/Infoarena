#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("oras1.in");
ofstream fout("oras1.out");

int dx[8] = {-1,-1,0,1,1,1,0,-1}, dy[8] = {0,1,1,1,0,-1,-1,-1};
int n,m, a[205][205],bin[205][205], sol, cladiri, maxx = 0,l;
char c;
int cont(int i, int j)
{
    for(int k = 0; k <= 7; ++k)
    {
        if(a[i+dx[k]][j+dy[k]] == -1)
            return 1;
    }
    return 0;
}
void fill(int i, int j)
{
    a[i][j] = 0;

    for(int k = 0; k <= 7; k = k+2)
    {
        if(a[i+dx[k]][j+dy[k]] == 1)
             fill(i+dx[k],j+dy[k]);
    }
}
void parc(int i, int j)
{
    a[i][j] = 0;
    for(int k  = 0; k<=7; k = k+2)
    {
        if(a[i+dx[k]][j+dy[k]] == 2)
        {
            l++;
            parc(i+dx[k],j+dy[k]);
        }
    }
}
int main()
{
   fin >> n >> m;
   for(int i= 1; i <= n; ++i)
   {
       for(int j = 1; j <= m; ++j)
       {
           fin >> c;
           if(c == '.') a[i][j] = bin[i][j] = -1;
           else if(c=='C') a[i][j] = bin[i][j] = 1;
           else if(c == 'P') a[i][j] = bin[i][j] = 2;
           else if(c == 'S') a[i][j] = bin[i][j] = 3;
       }
   }
   for(int i = 1; i <= n; ++i)
   {
       for(int j = 1; j <= m; ++j)
       {
           if(((i==1||i==n||j==1||j==m)&&a[i][j]>0)|| (a[i][j] > 0 && cont(i,j)))
            sol++;

       }
   }

   for(int i = 1; i <= n; ++i)
   {
       for(int j = 1; j <= m; ++j)
       {
           if(a[i][j] == 1)
           {

               cladiri++;
               fill(i,j);
           }
           else if(a[i][j] == 2)
           {
               l = 1;
               parc(i,j);
               if(l>maxx)
                maxx = l;
            }
       }
   }
   fout<<sol<<' '<<cladiri<<' '<<maxx<<'\n';



}
