#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

ifstream f("euclid4.in");
ofstream g("euclid4.out");

int n[205], nn;
int a[202], b[202], c[410], na = 0, nb = 0, nc = 0;

/*void BruteForce()// PROGRAMARE DINAMICA
{
    int n2;
    cin >> n2;
    int sol = 0, x, y;
    for(int i = 1; i <= n2; ++i)
        dp[i][i] = dp[i][1] = 1;
    for(int i = 3; i <= n2; ++i)
    {
        for(int j = 2; j < i; ++j)
        {
            dp[i][j] = dp[j][i % j] + 1;
            if(dp[i][j] > sol)
            {
                sol = dp[i][j];
                x = i; y = j;
            }
        }
    }
    cout << sol << '\n' << x << ' ' << y << '\n';
}*/

void Produs(int na, int a[], int nb, int b[], int &nc, int c[])
{
    nc = na + nb - 1;
    for(int i = 0; i <= nc; ++i) c[i] = 0;
    for(int i = 0; i < na; ++i)
    {
        for(int j = 0; j < nb; ++j)
        {
            c[i + j] += a[i] * b[j];
        }
    }
    for(int i = 1; i < nc; ++i)
    {
        c[i] = c[i] + c[i - 1] / 10;
        c[i - 1] %= 10;
    }
    while(c[nc - 1] > 9)
    {
        c[nc] = c[nc] + c[nc - 1] / 10;
        c[nc - 1] %= 10;
        nc++;
    }
}

void Show(int nx, int x[])
{
    for(int i = nx - 1; i >= 0; --i) g << x[i];
    g << '\n';
}

void Add(int na, int a[], int nb, int b[], int &nc, int c[])
{
      int i, t = 0;
      for (i = 0; i < na || i < nb || t; i++, t/=10)
              c[i] = (t += a[i] + b[i]) % 10;
      nc = i;
}

void Read()
{
    char s[205];
    f.get(s, 205);
    nn = strlen(s);
    for(int i = 0; i < nn; ++i) n[nn - i - 1] = s[i] - '0';
}

bool MaiMare(int nx, int x[])
{
    if(nx < nn) return false;
    else if(nx > nn) return true;
    else
    {
        for(int i = nx - 1; i >= 0; --i)
        {
            if(x[i] > n[i]) return true;
            else if(x[i] < n[i]) return false;
        }
    }
}

void Atribuie(int nx, int x[], int &ny, int y[])
{
    ny = nx;
    for(int i = 0; i <= ny; ++i) y[i] = x[i];
}

int main()
{
    b[nb++] = 2; a[na++] = 1; c[nc++] = 3;
    int sol = 2;
    Read();
    while(MaiMare(nc, c) == false)
    {
        sol++;
        Atribuie(nb, b, na, a);
        Atribuie(nc, c, nb, b);
        Add(na, a, nb, b, nc, c);
    }
    g << sol << '\n';
    Show(na, a);
    Show(nb, b);
}
