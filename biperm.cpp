#include <iostream>
#include <fstream>
#include <vector>
#define NM 10005
using namespace std;

ifstream f("biperm.in");
ofstream g("biperm.out");

int n, s1[NM], s2[NM], sol = 1, kmin, sens1, sens2, v[NM], use[NM][2];
vector < int > graf[NM];

int main()
{
    int x, nod;
    f >> n;
    for(int i = 1; i <= n; ++i) f>> v[i], s1[i] = v[i];
    for(int i = 1; i <= n; ++i)
    {
        f >> s2[i];
        graf[v[i]].push_back(s2[i]);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(!use[v[i]][0])
        {
            sens1 = 0;
            sens2 = 0;
            nod = v[i];
            while(graf[nod].size() && !use[nod][0])
            {
                use[nod][0] = 1;
                nod = graf[nod][0];
                sens1++;
            }
            if(nod == v[i])
            {
                sol *= 2;
            }
            else
            {
                int aux;
                sol *= 2;
                sens2 = 1;
                nod = graf[ v[ i ] ][1];
                while(graf[nod].size() && !use[nod][0])
                {
                    use[nod][0] = 1;
                    nod = graf[nod][0];
                    sens2++;
                }
                if(min(sens1, sens2) == 0) kmin += 1;
                else kmin += min(sens1, sens2);
            }
        }
    }
    g << sol << ' ' << kmin;
}
