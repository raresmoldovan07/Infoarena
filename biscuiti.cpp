#include <bits/stdc++.h>
using namespace std;

ifstream f("biscuiti.in");
ofstream g("biscuiti.out");

const long long inf = 1e18;
const int NMax = 100005;

long long segmentTree[4 * NMax], lazy[4 * NMax], poz[4 * NMax];
int n;

void Update(long long segmentTree[], int startRange, int endRange, int left, int right, long long value, int node)
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
        else
        {
            poz[node] = startRange; /** LEAF NODE **/
        }
        return;
    }

    int midRange = (startRange + endRange) >> 1;
    Update(segmentTree, startRange, midRange, left, right, value, 2 * node);
    Update(segmentTree, midRange + 1, endRange, left, right, value, 2 * node + 1);
    if(segmentTree[2 * node] <= segmentTree[2 * node + 1])
    {
        segmentTree[node] = segmentTree[2 * node];
        poz[node] = poz[2 * node];
    }
    else
    {
        segmentTree[node] = segmentTree[2 * node + 1];
        poz[node] = poz[2 * node + 1];
    }
}

pair < long long, long long > Query(long long segmentTree[], int startRange, int endRange, int left, int right, int node)
{
    if(startRange > endRange) return {inf, 0};

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
    if(startRange > right || left > endRange) return {inf, 0};

    /** TOTAL OVERLAP **/
    if(left <= startRange && endRange <= right)
    {
        return make_pair(segmentTree[node], poz[node]);
    }

    int midRange = (startRange + endRange) >> 1;
    pair < long long , long long> ans1 = Query(segmentTree, startRange, midRange, left, right, 2 * node);
    pair < long long, long long> ans2 = Query(segmentTree, midRange + 1, endRange, left, right, 2 * node + 1);
    if(ans1.first <= ans2.first)
    {
        poz[node] = poz[2 * node];
        return ans1;
    }
    else
    {
        poz[node] = poz[2 * node + 1];
        return ans2;
    }
}


int main()
{
    long long val, sum = 0, sum2 = 0, poz2;
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        f >> val;
        sum += val;
        Update(segmentTree, 1, n, i, i, val, 1);
    }
    for(int i = 1; i <= n; ++i)
    {
        val = Query(segmentTree, 1, n, 1, n, 1).first;
        poz2 = Query(segmentTree, 1, n, 1, n, 1).second;
        sum2 += val;
        if(i < n)
        {
            Update(segmentTree, 1, n, 1, poz2 - 1, i, 1);
            Update(segmentTree, 1, n, poz2, poz2, inf - val, 1);
        }
    }
    g << sum2 - sum;
}
