#include <iostream>
#include <fstream>
using namespace std;

ifstream f("text.in");

int a1, a2, a[10][10], b1, b2, b[10][10], c[10][10], c1, c2;

int main()
{
    f >> a1 >> a2;
    for(int i = 1; i <= a1; ++i)
        for(int j = 1; j <= a2; ++j)
            f >> a[i][j];

    f >> b1 >> b2;
    for(int i = 1; i <= b1; ++i)
        for(int j = 1; j <= b2; ++j)
            f >> b[i][j];

    c1 = a1;
    c2 = b2;
    for(int i = 1; i <= a1; ++i)
    {
        for(int j = 1; j <= b2; ++j)
        {
            int s = 0;
            for(int p = 1; p <= a2; ++p)
                s += (a[i][p] * b[p][j]);
            c[i][j] = s;
        }
    }
    for(int i = 1; i <= c1; ++i)
    {
        for(int j = 1; j <= c2; ++j)
            cout << c[i][j] << ' ';
        cout << endl;
    }
}
