#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

ifstream f("cezar.in");
ofstream g("cezar.out");

const int NMax = 10005;

vector < int > graf[NMax];
priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > heap;
queue < int > q;
int n, k, vec[NMax], used, use[NMax];

int main()
{
    int x, y, root, total = 0;
    f >> n >> k;
    for(int i = 1; i < n; ++i)
    {
        f >> x >> y;
        graf[x].push_back(y);
        vec[x]++;
        graf[y].push_back(x);
        vec[y]++;
    }

    for(int i = 1; i <= n; ++i)
    {
        if(graf[i].size() == 1)
        {
            heap.push({1, i});
        }
            use[i] = 1;
    }

    while(used < n - k - 1 && heap.empty() == false)
    {
        int node = heap.top().second;
        int nr = heap.top().first;
        heap.pop();
        used++;
        for(auto it : graf[node])
        {
            vec[it]--;
            use[it] += nr;
            if(vec[it] == 1)
                heap.push({use[it], it});
        }
        total += nr;
    }
    g << total << '\n';

}
