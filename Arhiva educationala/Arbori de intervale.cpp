#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

int v[] = {0, 1, 3, 4, 2, 5, 1, 9, 3}, n = 8;
int segmentTree[100], lazy[100];

void Update(int segmentTree[], int startRange, int endRange, int pos, int value, int node)
{
    if(startRange > endRange) return;

    if(pos < startRange || pos > endRange) return;

    if(startRange == endRange)
    {
        segmentTree[node] += value;
        return;
    }

    int midRange = (startRange + endRange) >> 1;
    Update(segmentTree, startRange, midRange, pos, value, 2 * node);
    Update(segmentTree, midRange + 1, endRange, pos, value, 2 * node + 1);
    segmentTree[node] = max(segmentTree[2 * node], segmentTree[2 * node + 1]);
}

int Query(int segmentTree[], int startRange, int endRange, int left, int right, int node)
{
    if(startRange > endRange) return -inf;

    if(startRange > right || left > endRange) return -inf;

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
        Update(segmentTree, 1, n, i, v[i], 1);
    for(int i = 1; i <= 20; ++i)
    {
        int q, x, y;
        cin >> q >> x >> y;
        if(q == 1)
            Update(segmentTree, 1, n, x, y, 1);
        else cout << Query(segmentTree, 1, n, x, y, 1) << '\n';

    }
}
