#include <fstream>
#include <iostream>
using namespace std;



int calc(int n)
{
    int s = 0;
    while(n)
    {
        s += n % 10;
        n/=10;
    }
    return s;

}

int main()
{
    ifstream f("piata.in");
    ofstream g("piata.out");
    long long sum = 0;
    short n, x1, x2, y1, y2,   v[40005];
    f >> n >> x1 >> y1 >> x2 >> y2;
    for(int i = 1; i <= n; ++i)
        v[i] = calc(i);
    for(int i = x1; i <= x2; ++i)
        for(int j = y1; j <= y2; ++j)
        {
            if(i <= j)
                sum+=v[j-i+1];
            else sum += v[j+n-i+1];
        }

    g<<sum;
    g.close();
    return 0;
}
