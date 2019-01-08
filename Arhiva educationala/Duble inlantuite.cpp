#include <bits/stdc++.h>
using namespace std;

struct nod
{
    int info;
    nod *urm, *prec;
};

nod *prim, *ultim, *p, *nou;

void create()
{
    prim = new nod;
    ultim = new nod;
    prim -> urm = ultim;
    prim -> prec = NULL;
    ultim -> urm = NULL;
    ultim -> prec = prim;
}

void citire(nod * &prim , nod * &ultim)
{
    for(int i = 1; i <= 5; ++i)
    {
        nou = ultim;
        cin >> nou -> info;
        ultim = new nod;
        nou -> urm = ultim;
        ultim -> prec = nou;
        ultim -> urm = NULL;
    }
}

void show()
{
    p = prim -> urm;
    while(p != ultim)
    {
        cout << p -> info << ' ';
        p = p->urm;
    }
}

int main()
{
    create();
    citire(prim, ultim);
    show();
}
