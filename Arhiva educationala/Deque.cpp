#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

ifstream f("deque.in");
ofstream g("deque.out");

struct a
{
    int val, poz;
} x;
deque <a> dq;
int n, st, dr, k;
long long s;

int main()
{
    f >> n >> k;
    for(int i = 1; i <= k; ++i)
    {
        f >> x.val;
        x.poz = i;
        while(!dq.empty() && x.val <= dq.back().val )
            dq.pop_back();
        dq.push_back(x);
    }
    s = dq.front().val;
    st = 1;
    dr = k;
    for(int i = k + 1; i <= n; ++i)
    {
        st++;
        dr++;
        f >> x.val;
        x.poz = i;
        if(st > dq.front().poz) dq.pop_front();
        while(!dq.empty() && x.val <= dq.back().val)
            dq.pop_back();
        dq.push_back(x);
        s += dq.front().val;
    }
    g << s;
}
