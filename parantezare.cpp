#include <iostream>
#include <stack>
#include <fstream>
#include <string.h>
#define NM 100100
using namespace std;

ifstream f("parantezare.in");
ofstream g("parantezare.out");

stack < int > stiva;


int main()
{
    char c[NM];
    int i = 0, m, n, v[2*NM];
    f.getline(c,NM);
    n = strlen(c) - 1;
    while(i <= n )
    {

        if(c[i] == '(') stiva.push(i);
        if(c[i] == ')') v[stiva.top()] = i, stiva.pop();

        i++;
    }
    f >> m;
    int x;
    for(int i = 1; i <= m; ++i)
    {
        f >> x;
        g << v[x] << ' ';
    }
    g << '\n';

}
