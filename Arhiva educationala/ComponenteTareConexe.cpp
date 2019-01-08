#include <bits/stdc++.h>
using namespace std;

ifstream f("ctc.in");
ofstream g("ctc.out");

const int NMax = 100005;

int n, m, number_components, used[ NMax ];
stack < int > topological_order;
vector < int > G[ NMax ], GT[ NMax ];
vector < int > component[ NMax ];

void DFS(int node)
{
    used[ node ] = 1;
    for(int i = 0; i < G[ node ].size(); ++i)
        if(!used[ G[ node ][ i ] ])
            DFS( G[ node ][ i ] );
    topological_order.push(node);
}

void DFST(int node)
{
    used[ node ] = 1;
    component[ number_components ].push_back( node );
    for(int i = 0; i < GT[ node ].size(); ++i)
        if(!used[ GT[ node ][ i ] ])
            DFST(GT[ node ][ i ]);
}

int main()
{
    int x, y;
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        f >> x >> y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }

    for(int node = 1; node <= n; ++node)
    {
        if(!used[node])
            DFS(node);
    }
    for(int node = 1; node <= n; ++node) used[ node ] = 0;

    while(!topological_order.empty())
    {
        int node = topological_order.top();
        topological_order.pop();
        if(!used[ node ])
        {
            number_components++;
            DFST( node );
        }
    }

    g << number_components << '\n';
    for(int i = 1; i <= number_components; ++i)
    {
        for(int j = 0; j < component[ i ].size(); ++j)
            g << component[ i ][ j ] << ' ';
        g << '\n';
    }
}

