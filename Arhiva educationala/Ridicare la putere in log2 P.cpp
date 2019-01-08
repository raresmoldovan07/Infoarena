#include <iostream>
using namespace std;

int main()
{
    long long n, p, x = 1;
    cin >> n >> p;
    while(p)
    {
       if(p & 1) x = (x * n) % mod;
       n = (n * n) % mod;
       p >>= 1;
    }
    cout << x;
}
