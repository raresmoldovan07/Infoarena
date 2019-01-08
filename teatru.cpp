#include <fstream>
using namespace std;

ifstream fin("operatii.in");
ofstream fout("operatii.out");

int main()
{
    int n, x, x2;
    long long sol = 0;
    fin >> n >> x2;
    sol = x2;
    for(int i = 2; i <= n; ++i)
    {
        fin >> x;
        if(x>x2)
            sol+=x-x2;
        x2 = x;
    }
    fout<<sol;
}
