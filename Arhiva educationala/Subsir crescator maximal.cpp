#include <iostream>
#include <fstream>
#include <stack>
#define INF 0x3f3f3f3f
#define NM 100010
using namespace std;

ifstream f("scmax.in");
ofstream g("scmax.out");

stack < int > stiva;
int n, v[NM], k, poz[NM], tail[NM];

void Read()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> v[ i ];
}

int BS(int st, int dr, int key)
{
    int mid;
    while(st <= dr)
    {
        mid = (st + dr) >> 1;
        if(v[tail[mid]] < key) st = mid + 1;
        else dr = mid - 1;
    }
    if(key <= v[tail[st]]) return st;
    return st - 1;

}

void Solve()
{
    int p;
    poz[1] = 0;
    tail[++k] = 1;
    for(int i = 2; i <= n; ++i)
    {
        if(v[ i ] < v[ tail[ 1 ] ])
        {
            tail[1] = i;
        }
        else if(v[ i ] > v[ tail[ k ] ])
        {
            tail[++k] = i;
            poz[i] = tail[k - 1];
        }
        else
        {
            p = BS(1, k, v[i]);
            if(v[i] <= v[tail[p]])
            {
                tail[p] = i;
                poz[i] = tail[p - 1];
            }
        }
    }
}

void Write()
{
    g << k << '\n';
    int i = tail[k];
    while(i)
    {
        stiva.push(v[i]);
        i = poz[i];
    }
    while(stiva.empty() == false)
    {
        g << stiva.top() << ' ';
        stiva.pop();
    }
}

int main()
{
    Read();
    Solve();
    Write();
}
