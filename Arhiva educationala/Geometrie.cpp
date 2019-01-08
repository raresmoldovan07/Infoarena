#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

struct punct
{
    double x, y;
};

punct a, b, c;

bool verifica(punct a, punct b, punct c)
{
    if( (c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x) ) return false;//PUNCTUL NU APARTINE DREPTEI
    return (min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x)) && (min(a.y, b.y) <= c.y && c.y <= max(a.x, b.x));
}

int main()
{
    while(1)
    {
        system("pause");
        system("cls");
        cout << "a.x = "; cin >> a.x;
        cout << "a.y = "; cin >> a.y;
        cout << "b.x = "; cin >> b.x;
        cout << "b.y = "; cin >> b.y;
        cout << "c.x = "; cin >> c.x;
        cout << "c.y = "; cin >> c.y;
        cout << verifica(a, b, c);
    }
}
