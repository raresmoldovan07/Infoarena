#include <iostream>
#include <stack>
#include <string>
#include <fstream>

using namespace std;

ifstream f("evaluare.in");
ofstream g("evaluare.out");

stack < int > st;
stack < char > op;
string s;

int prop[300];

void calc()
{
    if(st.size() >= 2)
    {
        int s1 = st.top();
        st.pop();
        int s2 = st.top();
        st.pop();
        if(op.top() == '*') st.push(s1 * s2);
        else if(op.top() == '+') st.push(s1 + s2);
        else if(op.top() == '-') st.push(s2 - s1);
        else if(op.top() == '/') st.push(s2 / s1);
        op.pop();
    }
}

int main()
{
    prop[ '*' ] = prop[ '/' ] = 2;
    prop[ '+' ] = prop[ '-' ] = 1;
    f >> s;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[ i ] == '(') op.push( '(' );
        else if( isdigit( s[ i ] ) )
        {
            int nr = 0;
            while( isdigit( s[ i ] ))
            {
                nr = nr * 10 + (s[ i ] - '0');
                i++;
            }
            st.push(nr);
            i--;
        }
        else if(s[ i ] == ')')
        {
            while(op.top() != '(') calc();
            op.pop();
        }
        else
        {
            while( op.empty() == 0 && prop[ s[ i ] ] <= prop[ op.top() ] )
                calc();
            op.push( s[ i ] );
        }

    }
    while( !op.empty() )
        calc();
    g << st.top() << '\n';
}
