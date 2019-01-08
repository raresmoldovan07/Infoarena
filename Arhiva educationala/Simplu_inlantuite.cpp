#include <iostream>
#define n 5
using namespace std;

struct nod
{
    int info;
    nod *urm;
};

nod *prim, *nou, *p;

void show()
{
    nod *p = prim;
    while( p )
    {
        cout << p -> info << ' ';
        p = p -> urm;
    }
}

void insert_front()
{
    nou = new nod;
    cin >> nou -> info;
    nou -> urm = prim;
    prim = nou;
}

void insert_back()
{
    nou = new nod;
    cin >> nou -> info;
    p = prim;
    while(p -> urm) p = p -> urm;
    p -> urm = nou;
    nou -> urm = NULL;

}

void delete_front()
{
    nod *q;
    q = prim;
    prim = prim -> urm;
    delete q;
}

void delete_back()
{
    p = prim;
    while(p -> urm -> urm) p = p -> urm;
    p -> urm = NULL;
}

int main()
{
    prim = NULL;
    for(int i = 1; i <= n; ++i)
    {
        nou = new nod;
        cin >> nou -> info;
        if(i == 1)
        {
            nou -> urm = prim;
            prim = nou;
        }
        else
        {
            p = prim;
            while(p -> urm) p = p -> urm;
            p -> urm = nou;
            nou -> urm = NULL;
        }
    }
    //cout << "new: ";
    delete_back();
    show();
}
