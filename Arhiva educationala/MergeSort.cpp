#include <iostream>
using namespace std;

int n,v[1000], b[1000];

struct Graph{

    int cost, node;
    Graph *next;
};


void MergeSort(int st, int dr)
{
    int m = (st + dr) >> 1, k,i,j;
    if(st == dr) return;
    MergeSort(st, m);
    MergeSort(m + 1, dr);
    for(i = st, k = st, j = m + 1; i <= m || j <= dr;)
    {
        if(j > dr || (i <= m && v[i] < v[j]))
        {
            b[k++] = v[i++];
        }
        else b[k++] = v[j++];
    }
    for(i = st; i <= dr; ++i)
        v[i] = b[i];


}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    MergeSort(1, n);
    for(int i = 1; i <= n; ++i)
        cout << v[i] << ' ';
    return 0;

}
