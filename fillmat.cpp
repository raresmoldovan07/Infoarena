#include <iostream>
#include <fstream>

ifstream fin("fillmat.in");
ofstream fout("fillmat.out");

int a[305][305], sum, sumf, n, sol;
int dx[8] = {-1,-1,0,1,1,1,0,-1}, dy[8] = {0,1,1,1,0,-1,-1,-1};

void Read()
{
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        fin>>a[i][j], sum += a[i][j];
}


int main()
{
    fin >> n;
    sumf = n*n;
    Read();
}
