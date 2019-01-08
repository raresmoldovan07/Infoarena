#include <string.h>
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

ifstream f("ordonare.in");
ofstream g("ordonare.out");

int v[300],n;
char alfa[40], S[3000];

struct z
{
    char s[100];
} cuv[1100];

bool cmp(const z &b, const z &c)
{
    int n = strlen(b.s) - 1;
    int m = strlen(c.s) - 1;
    for(int i = 0; i <= m || i <= n; ++i)
    {
        if(v[c.s[i]] < v[b.s[i]]) return false;
        else if(v[c.s[i]] > v[b.s[i]]) return true;
    }
}

int main()
{
    char *pch;
    f.getline(alfa,40);
    n = strlen(alfa) -  1;
    for(int i = 0; i <= n; ++i)
        v[alfa[i]] = i;
    f.getline(S,2200);
    pch = strtok(S," .,:;?!");
    n = 1;
    strcpy(cuv[1].s, pch);
    while(pch != NULL)
    {
        n++;
        pch = strtok(NULL," .,:;?!");
        if(pch!=NULL )
            strcpy(cuv[n].s,pch);
    }
    sort(cuv+1,cuv+n+1,cmp);
    for(int i = 1; i <= n; ++i)
        if(cuv[i].s[0] != '\0' ) g << cuv[i].s << ' ' ;
    g << '\n';
    return 0;

}
