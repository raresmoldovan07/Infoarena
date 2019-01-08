#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define inf 0x3f3f3f3f

using namespace std;

ifstream f("dijkstra.in");
ofstream g("dijkstra.out");

vector < pair < int, int > > G[ 50005 ];
int t, n, m,  cost[ 50005 ], viz[ 50005 ];
queue < int > q;

int main()
{
    int x, y, c, nod;
    f >> n >> m;
    for(int i = 1; i <= n; ++i) cost[ i ] = inf;
    for(int i = 1; i <= m ;++i)
    {
        f >> x >> y >> c;
        G[ x ].push_back(make_pair(y, c));
    }
    q.push(1);
    cost[ 1 ] = 0;
    while(!q.empty())
    {
        nod = q.front();
        q.pop();
        viz[ nod ] = 0;
        for(int i = 0; i < G[ nod ].size(); ++i)
        {
            if(cost[ G[ nod ][ i ].first ] > cost[ nod ] + G[ nod ][ i ].second)
            {
                cost[ G[ nod ][ i ].first ] = cost[ nod ] + G[ nod ][ i ].second;
                if(!viz[ G[ nod ][ i ].first ])
                {
                    q.push( G[ nod ][ i ].first );
                    viz[ G[ nod ][ i ].first ] = 1;
                }
            }
        }
    }
    for(int i = 2; i <= n; ++i)
    {
        if(cost[ i ] != inf) g << cost[ i ] << ' ';
        else g << "0" << ' ';
    }
}



