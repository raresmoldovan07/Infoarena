#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

ifstream f("infasuratoare.in");
ofstream g("infasuratoare.out");

struct punct
{
    double x, y;
};

punct v[120005], stiva[120005];
int n, vf;

void Read()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> v[i].x >> v[i].y;
}

double Produs(const punct& a, const punct& b, const punct& c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool cmp(const punct& a, const punct& b)
{
     return Produs(v[1], a, b) < 0;
}

void Solve()
{
    int minn = 1;
    for(int i = 2; i <= n; ++i)
    {
        if(v[i].x < v[minn].x) minn = i;
        else if(v[i].x == v[minn].x && v[i].y < v[minn].y) minn = i;
    }
    swap(v[1], v[minn]);
    sort(v + 2, v + n + 1, cmp);

    stiva[1] = v[1];
    stiva[2] = v[2];
    vf = 2;
    for(int i = 3; i <= n; ++i)
    {
        while(vf >= 2 && Produs(stiva[vf - 1], stiva[vf], v[i]) > 0)
            --vf;
        stiva[++vf] = v[i];
    }
}

void Write()
{
    g << vf << '\n';
    g << fixed;
    for(int i = vf; i >= 1; --i)
    {
        g << setprecision(12) << stiva[i].x << ' ' << stiva[i].y << '\n';
    }
}

int main()
{
    Read();
    Solve();
    Write();
}

