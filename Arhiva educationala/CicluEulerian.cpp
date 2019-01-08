#include <bits/stdc++.h>
using namespace std;

ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");

const int NMax = 100005, MMax = 500005;

stack < int > mystack;
vector < pair < int, int > > graph[NMax];
vector < int > ans;
bool use[MMax];
int n, m;

int main()
{
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int x, y;
        f >> x >> y;
        graph[x].push_back(make_pair(y, i));
        graph[y].push_back(make_pair(x, i));
    }
    for(int node = 1; node <= n; ++node)
        if(graph[node].size() & 1 || graph[node].size() == 0)
        {
            g << -1 << '\n';
            return 0;
        }
    mystack.push(1);
    while(!mystack.empty())
    {
        int node = mystack.top();

        if(graph[node].size())
        {
            int x = graph[node].back().first;
            int edge = graph[node].back().second;
            graph[node].pop_back();
            if(!use[edge])
            {
                use[edge] = true;
                mystack.push(x);
            }
        }
        else
        {
            mystack.pop();
            ans.push_back(node);
        }
    }
    for(int i = 0; i < ans.size() - 1; ++i)
        g << ans[i] << ' ';
    return 0;

}
