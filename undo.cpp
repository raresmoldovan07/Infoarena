#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ifstream f("undo.in");
ofstream g("undo.out");

int n;
vector < int > myvector;
vector < int > trash;


int main()
{
    int i,o,x;
    f >> n;

    for(int k = 1; k <= n; ++k)
    {
        f >> o >> x;
        if( o == 1 )
        {
            myvector.push_back( x );

        }
        else if ( o == 2 )
        {
            i = 0;
            while(i < x)
            {
                trash.push_back( *(myvector.end()-1) );
                myvector.pop_back();
                i++;

            }
        }
        else if( o == 3)
        {
            i = 0;
            while(i < x)
            {
                myvector.push_back( *(trash.end()-1) );
                trash.pop_back();
                i++;

            }
        }
        else
        {

            int nr = 0;
            for( vector < int >:: iterator it = myvector.begin(); it != myvector.end(); ++it)
                if(*it == x) nr++;
            g << nr << '\n';
        }


    }
    return 0;
}
