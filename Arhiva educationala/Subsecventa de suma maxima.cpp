#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


int s[7000000], n, i;

int main()
{
     ifstream fin("ssm.in");
     ofstream fout("ssm.out");
     fin >> n;
     for(i = 1; i <= n; ++i)
     {
         fin >> s[i];
     }
     int indx, end, min=0, beg, smaxx=-2000000;

     for(i = 1; i <= n; ++i)
     {
         s[i] = s[i] + s[i-1];
         if(s[i]-min > smaxx) smaxx = s[i]-min, beg = indx+1, end = i;
         if(min > s[i])
            min = s[i], indx = i;
     }
     fout << smaxx << ' ' << beg << ' ' << end;

}
