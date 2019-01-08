#include <iostream>
#include <deque>
#include <fstream>
#define NM 16005
#define inf 0x3f3f3f3f
using namespace std;

ifstream f("trans.in");
ofstream g("trans.out");

int s[NM][2], best[NM][2], n;

void insert(deque < pair < int, int > > &dq, pair< int, int > p)
{
    while(dq.empty() == false && p.second < dq.back().second)
            dq.pop_back();
    dq.push_back(p);
}

int query(deque < pair < int, int > > &dq, int poz)
{
    while(dq.front().first < poz && dq.empty() == false)
        dq.pop_front();
    return dq.front().second;
}

int Solve(int k, int t)
{
    deque < pair < int, int > > dq[2];
    insert(dq[0], pair < int, int > (0,0));
    insert(dq[1], pair < int, int > (0,0));

    for(int i = 1; i <= n; ++i)
    {
        best[i][1] = query(dq[1], i - k) + s[i][1] + t;
        best[i][0] = query(dq[0], i - k) + s[i][0] + t;

        insert(dq[1], pair < int, int > (i, min(best[i][1], best[i][0]) - s[i][1]));
        insert(dq[0], pair < int, int > (i, min(best[i][0], best[i][1]) - s[i][0]));
    }
    return min(best[n][1], best[n][0]);

}

int main()
{
    int c, sum,k,t,q;
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        f >> c >> sum;
        for(int j = 0; j <= 1; ++j) s[i][j] += s[i-1][j];
        s[i][1 - c] += sum;
    }
    f >> q;
    for(int i = 1; i <= q; ++i)
    {
        //cout << "nu";
        f >> k >> t;
        g << Solve(k, t) << '\n';
    }
}
