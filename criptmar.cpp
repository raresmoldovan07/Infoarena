#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main()
{
    char a[200][200], s[255];
    int n,i = 0,d;
    ifstream fin("criptmat.in");
    ofstream fout("criptmat.out");
    fin>>n;
    fin.getline(s,2);
    while(fin.get(s,n+1))
    {
        i++;
        d = 0;
        if(i%2==1)
            strcpy(a[i],s);
        else
            for(int k = n-1; k >= 0; --k)
                a[i][d] = s[k], d++;


    }
    for(int k = 0; k <n; ++k)
        for(int j = 1; j <= i; ++j)
            fout<<a[j][k];

}
