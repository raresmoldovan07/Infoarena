#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

ifstream f("text.in");

struct Comp
{
    bool operator()(const pair < string, int >& left, const pair < string, int >& right) const
    {
        if(left.first < right.first) return true;
        else if(left.first > right.first) return false;
        else return left.second < right.second;
    }
};

struct Comp_Tree
{
    bool operator()(const int& left, const int& right) const
    {
        return left < right;
    }
};

struct Comp_Queue
{
    bool operator()(const pair < int, char >& left, const pair < int, char >& right) const
    {
        return left.second < right.second;
    }
};

multiset < pair < string, int >, Comp > multi_tree;
set < int, Comp_Tree > tree;
priority_queue < pair < int, char >, vector < pair < int, char > >, Comp_Queue > q;

void Read()
{
    int n, x;
    char c;
    f >> n;
    while(n--)
    {
        f >> x >> c;
        tree.insert(x);
        q.push(make_pair(x, c));
    }
}

int main()
{
    Read();
    while(q.empty() == false)
    {
        cout << q.top().first << ' ' << q.top().second << '\n';
        q.pop();
    }
    cout << endl;
    for(set < int > :: iterator node = tree.begin(); node != tree.end(); ++node)
        cout << *node << ' ';
}
