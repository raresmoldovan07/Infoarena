
#include <iostream>
#include <algorithm>
using namespace std;

int m[100], v[100], n, uz[100], s[100];

void gen(int k)
{
    if(k == n+1)
    {
        for(int i = 1; i <= n; ++i)
            cout << s[i] << ' ';
        cout << endl;
    }
    else
    {
        for(int i = 1; i <= n; ++i)
        {
            if( uz[v[i]] < m[v[i]] )
            {
                uz[v[i]]++;
                s[k] = v[i];
                gen(k+1);
                uz[v[i]]--;
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i]; m[v[i]]++;
    }
    gen(1);
}
