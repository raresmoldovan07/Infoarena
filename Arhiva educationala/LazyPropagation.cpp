#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

int v[] = {0, 1, 3, 4, 2, 5, 1, 9, 3}, n = 8;
int segmentTree[100], lazy[100];

void Update(int segmentTree[], int startRange, int endRange, int left, int right, int value, int node)
{
    if(startRange > endRange) return;

    if(lazy[node] != 0)
    {
        segmentTree[node] += lazy[node];
        if(startRange != endRange) /** NOT A LEAF NODE **/
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    /** NO OVERLAP **/
    if(right < startRange || left > endRange) return;

    /** TOTAL OVERLAP **/
    if(left <= startRange && endRange <= right)
    {
        segmentTree[node] += value;
        if(startRange != endRange)
        {
            lazy[2 * node] += value;
            lazy[2 * node + 1] += value;
        }
        return;
    }

    int midRange = (startRange + endRange) >> 1;
    Update(segmentTree, startRange, midRange, left, right, value, 2 * node);
    Update(segmentTree, midRange + 1, endRange, left, right, value, 2 * node + 1);
    segmentTree[node] = max(segmentTree[2 * node], segmentTree[2 * node + 1]);
}

int Query(int segmentTree[], int startRange, int endRange, int left, int right, int node)
{
    if(startRange > endRange) return -inf;

    if(lazy[node] != 0)
    {
        segmentTree[node] += lazy[node];
        if(startRange != endRange) /** NOT A LEAF NODE **/
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    /** NO OVERLAP **/
    if(startRange > right || left > endRange) return -inf;

    /** TOTAL OVERLAP **/
    if(left <= startRange && endRange <= right)
    {
        return segmentTree[node];
    }

    int midRange = (startRange + endRange) >> 1;
    return max(Query(segmentTree, startRange, midRange, left, right, 2 * node),
               Query(segmentTree, midRange + 1, endRange, left, right, 2 * node + 1));
}


int main()
{
    for(int i = 1; i <= n; ++i)
        Update(segmentTree, 1, n, i, i, v[i], 1);
    for(int i = 1; i <= 20; ++i)
    {
        int q, x, y, val;
        cin >> q >> x >> y;
        if(q == 1)
        {
            cin >> val;
            Update(segmentTree, 1, n, x, y, val, 1);
        }
        else cout << Query(segmentTree, 1, n, x, y, 1) << '\n';
    }
}
