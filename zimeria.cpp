#include <fstream>
#include <string.h>
#include <iostream>
#include <algorithm>
#define Nmax 400005
using namespace std;

ifstream f("zimeria.in");
ofstream g("zimeria.out");

int n, v[130];
char S[20];

struct z
{
    char s[7];
} cuv[Nmax];

bool cmp(const z &b, const z &c)
{
    return strcmp(b.s,c.s) < 0;
}
bool cmp2(const z &b, const z &c)
{
    for(int i = 0; i < 5; ++i)
        if(v[b.s[i]] > v[c.s[i]]) return false;
        else if(v[b.s[i]] < v[c.s[i]]) return true;
}
int main()
{
    int p, sol = 1;
    f >> p >> n;
    f.getline(cuv[0].s,2);
    for(int i = 1; i <= 12; ++i) f >> S[i], v[S[i]] = i;

    f.getline(cuv[0].s,2);
    for(int i = 1; i <= n; ++i) f.getline(cuv[i].s,6);
    if(p == 1)
    {
        sort(cuv+1,cuv+n+1, cmp);
        for(int i  = 2; i <= n; ++i)
            if(strcmp(cuv[i].s,cuv[i-1].s))
                sol++;
        g << sol;
    }
    else
    {
        sort(cuv+1,cuv+n+1,cmp2);
        for(int i  = 1; i <= n; ++i)
            g << cuv[i].s << '\n';
    }

}
