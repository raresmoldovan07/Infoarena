#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <time.h>
#define NMax 10
#define HMax 80
using namespace std;

ifstream f("scara2.in");
ofstream g("scara2.out");

int n, m, p, h, htot;
int sol[NMax], solmin[NMax], use[HMax], st[HMax];
double efmin = 10000, ef[NMax];

void Read()
{
    f >> h >> n >> m >> p;
}

double Get_Effort()
{
    ef[1] = sol[1];
    double x1, s, ma, minn;
    for(int i = 2; i <= n; ++i)
    {
        x1 = ef[i - 1] + sol[i];
        s = sol[i];
        for(int j = 2; i - j >= 0; ++j)
        {
            s += sol[i - j + 1];
            if(s > m) break;
            if(s / j + p + ef[i - j] < x1) x1 = s / j + ef[i - j] + p;
        }
        ef[i] = x1;
    }

    return ef[n];
}

void Back(int k)
{
    if(k == n + 1)
    {
        if(htot == h)
        {
            for(int i = 1; i <= n; ++i)
                sol[i] = st[i];
            do
            {
                double x = Get_Effort();
                if(x < efmin && efmin - x > 0.001)
                {
                    efmin = x;
                    for(int i = 1; i <= n; ++i) solmin[i] = sol[i];
                }
            }
            while(next_permutation(sol + 1, sol + n + 1));
        }
    }
    else
    {
        for(int i = st[k - 1] + 1; i <= m; ++i)
        {
            st[k] = i;
            htot += i;
            Back(k + 1);
            htot -= i;
        }
    }
}

void Write()
{
    g << fixed;
    g << setprecision(2) << efmin << '\n';
    for(int i = 1; i <= n; ++i)
        g << solmin[i] << ' ';
    g << '\n';
}

int main()
{
    clock_t start, finish;
    start = clock();
    Read();
    Back(1);
    Write();

    finish = clock();
    double elapsed_time = double(finish - start) / CLOCKS_PER_SEC;
    cout << fixed;
    cout << setprecision(4)<< elapsed_time;
}
