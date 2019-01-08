#include <fstream>
#include <math.h>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

ifstream f("aria.in");
ofstream g("aria.out");

struct
{
    double x, y;
}a[100005];

int n;
double sol;

int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> a[i].x >> a[i].y;
    a[n + 1] = a[1];
    for(int i = 1; i <= n; ++i)
    {
        sol += (a[i].x * a[i + 1].y - a[i + 1].x * a[i].y);
    }
    sol /= 2.0;
    if(sol < 0) sol = -sol;
    g << fixed << setprecision(5) << sol << '\n';
}
