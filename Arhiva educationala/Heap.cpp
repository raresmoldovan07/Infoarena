//MAX HEAP
#include <iostream>
#include <windows.h>
#include <algorithm>
using namespace std;

void Menu();
int H[100], n;

void Print()
{
    for(int i = 1; i <= n; ++i) cout << H[i] << ' ';
    cout << endl;
}

void Up_Heap(int k)
{
    while(k > 1 && H[k] > H[k / 2])
    {
        swap(H[k / 2], H[k]);
        k /= 2;
    }
}

void Down_Heap(int k)
{
    int son = 1;
    while(son)
    {
        if(2 * k <= n)
        {
            son = 2 * k;
            if(2 * k + 1 <= n && H[son] < H[2 * k + 1])
                son = 2 * k + 1;
            if(H[k] < H[son]) swap(H[k], H[son]), k = son;
            else son = 0;
        }
        else son = 0;
    }
}

void Citire()
{
    int k,x;
    system("cls");
    cout << "Numarul de elemente: ";
    cin >> k;
    for(int i = 1; i <= k; ++i)
    {
        cout << "Elementul " << i << ":";
        cin >> x;
        H[i] = x;
        Up_Heap(i);
    }
    n = k;
    Menu();
}

void Delete()
{
    int k;
    cout << "Pozitia elementului de sters: "; cin >> k;
    swap(H[k], H[n]);
    n--;
    if(k > 1 && H[k] < H[k / 2]) Up_Heap(k);
    Down_Heap(k);
    Menu();
}

void Insert()
{
    int x;
    system("cls");
    cout << "Elementul de inserat: ";
    cin >> x;
    H[++n] = x;
    Up_Heap(n);
    Menu();
}

void Menu()
{
    int x;
    system("cls");
    Print();
    cout << "1.Citire Heap" << endl;
    cout << "2.Inserare in Heap" << endl;
    cout << "3.Stergere din Heap" << endl;
    cout << endl << "Introduceti numarul de ordine al operatiei: ";
    cin >> x;
    switch(x)
    {
    case 1:
        Citire();
        break;
    case 2:
        Insert();
        break;
    case 3:
        Delete();
        break;
    }
}

int main()
{
    Menu();
}

