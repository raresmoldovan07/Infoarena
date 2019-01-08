#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

ifstream fin("text3.in");
ofstream fout("text3.out");

struct cuvant
{
    char s[23], x, y;

} cuv[20003];

int  minn,n, maxx;
char a[205];

int gasit(int poz, char c)
{
    for(int i = poz-1; i >= 1; --i)
        if(cuv[i].y == c)
            return i;
    return 0;

}


int main()
{
    int nr, sol[20000],solf[20000], i,j;
    char c;
    char * pch;
    while(fin.getline(a, 205))
    {
        if(a[0] != '\0')
        {
            pch = strtok(a," ");
            while(pch != NULL)
            {
                n++;
                strcpy(cuv[n].s, pch);
                cuv[n].x = cuv[n].s[0];
                cuv[n].y = cuv[n].s[strlen(cuv[n].s)-1];
                pch = strtok(NULL, " ");
            }
        }
    }

    for(int i = n-1; i >= 1; --i)
    {
        if(cuv[i].y == cuv[n].x)
        {

            j = i;
            nr = 1;
            sol[nr] = i;
            c = cuv[i].x;
            while(gasit(j,c)>0)
            {
                j = gasit(j,c);
                c = cuv[j].x;
                nr++;
                sol[nr] = j;
            }


            if(nr > maxx)
            {
                maxx = nr;
                for(int i = 1; i <= nr; ++i)
                    solf[i] = sol[i];
            }
        }
    }
    fout<<n<<'\n'<<n-maxx-1<<'\n';

    for(int i = maxx; i>=1; --i)
        fout<<cuv[solf[i]].s<<'\n';
    fout<<cuv[n].s<<'\n';


}
