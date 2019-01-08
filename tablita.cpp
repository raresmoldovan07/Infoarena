#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    int a, b, aux
    ;
    cin >> a >> b;
    if(a == b)
    {
        cout << 0;
        return 0;
    }
    if(b > a)
    {
        aux = a;
        a = b;
        b = aux;
    }
    if(a % 2) cout << a + b - 2;
    else cout << a - b;

}
