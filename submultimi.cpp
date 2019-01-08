#include <fstream>
#include <iostream>
using namespace std;
ifstream f("submultimi.in");
ofstream g("submultimi.out");

int st[25], n;

void backk ()
{
    for(int i=1; i<=st[0]; i++) g <<st[i]<< ' ';
    if(st[0])g <<'\n';

    for(int i=st[st[0]]+1; i<=n; ++i)
    {

        st[++st[0]]=i;
        backk();
        st[st[0]]=0;
        --st[0];
    }
}

int main()
{
    f >>n;
    backk();


    return 0;
}
