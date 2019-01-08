#include <fstream>
#include <iostream>
#include <deque>
using namespace std;

ifstream f("sir.in");
ofstream g("sir.out");

int n, x, y, z, v[100005], lg;
deque < int > dq_max, dq_min;

int query(deque <int> &dq, int j)
{
    while(!dq.empty() && j > dq.front())
        dq.pop_front();
    return v[dq.front()];
}

int main()
{
    int st, dr, j = 1;
    f >> n >> x >> y >> z;
    for(int i = 1; i <= n; ++i) f >> v[i];
    for(int i = 1; i <= n; ++i)
    {
        while( !dq_min.empty() && v[i] <= v[dq_min.back()]) dq_min.pop_back();
        while( !dq_max.empty() && v[i] >= v[dq_max.back()]) dq_max.pop_back();
        dq_min.push_back(i);
        dq_max.push_back(i);

        while( (j <= i - y || query(dq_max, j) - query(dq_min, j) > z) && j <= i - x + 1) j++;

        if(j <= i - x + 1 && query(dq_max, j) - query(dq_min, j) <= z)
        {
            if(lg <= i - j + 1)
            {
                lg = i - j + 1;
                st = j;
                dr = i;
            }
        }
    }
    if(lg) g << lg <<  ' ' << st << ' ' << dr << '\n';
    else g << "-1" << '\n';
}
