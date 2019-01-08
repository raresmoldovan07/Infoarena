#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

ifstream f("damesah.in");
ofstream g("damesah.out");

int x[100], use[100], n, nr, gasit;

int valid()
{
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j < i; ++j)
            if((x[i] - x[j] == i-j) || (x[i] - x[j] == -1*(i-j)))
            {
                return 0;
            }
    }
    return 1;
}
void show()
{
    for(int i = 1; i <= n; ++i)
        cout << x[i] << ' ';
    cout << '\n';
}

void backk(int k)
{
    do
    {
        if(valid())
        {
            nr++;
            if(!gasit)
                show();
        }
    }
    while(next_permutation(x+1,x+n+1));


}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        x[i] = i;
    backk(1);
    cout << nr;

}
