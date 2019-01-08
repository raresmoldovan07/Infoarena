#include <vector>
#include <fstream>
#include <iostream>
#define MOD 666013

using namespace std;

ifstream f("hashuri.in");
ofstream g("hashuri.out");

vector < int > mylist[MOD];
int n;

inline vector <int>:: iterator find_value(int key)
{
    int x = key % MOD;
    for(vector<int>::iterator it = mylist[x].begin(); it != mylist[x].end(); ++it)
    {
        if(*it == key) return it;
    }
    return mylist[x].end();
}

inline void insert_list(int key)
{
    int x = key % MOD;
    if(find_value(key) == mylist[x].end())
    {
        mylist[x].push_back(key);
    }
}

inline void delete_list(int key)
{
    int x = key % MOD;
    vector <int>::iterator it = find_value(key);
    if(it != mylist[x].end())
    {
        mylist[x].erase(it);
    }
}

int main()
{
    int op, key;
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        f >> op >> key;
        if(op == 1) insert_list(key);
        else if(op == 2) delete_list(key);
        else g << (find_value(key) != mylist[key % MOD].end()) << '\n';
    }
}
