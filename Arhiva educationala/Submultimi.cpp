#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;
ifstream f("submultimi.in");
ofstream g("submultimi.out");

int st[25], n;


int main()
{
    cin >> n;

    n = 1 << n;
    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; (1<<(j-1)) <= i; ++j)
            if( i& (1<<(j-1))) cout << j <<' ';
        cout << endl;

    }
    return 0;
}
