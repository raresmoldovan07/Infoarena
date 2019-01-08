#include <iostream>
#include <windows.h>

using namespace std;

int n, a[20][20], use[20][20], gasit, sol;
int dx[8] = {-2,-2,-1,1,2,2,-1,1};
int dy[8] = {-1,1,2,2,-1,1,-2,-2};

bool OK(int x, int y)
{
    return (x >= 1) && (y >= 1) && (x <= n) && (y <= n) && (use[ x ][ y ] == 0);
}

void show()
{
    _sleep(90);
    system("cls");
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            cout << a[ i ][ j ] << '\t';
        cout << endl;
    }
}

void Backk(int k, int x, int y)
{
    a[x][y] = k;
    use[x][y] = 1;
    if(k == n * n )
    {
        show();
        sol++;
    }
    else
    {
        int xnou, ynou;
        for(int i = 0; i <= 7; ++i)
        {
            xnou = x + dx[i];
            ynou = y + dy[i];
            if( OK(xnou, ynou) )
            {
                k++;
                Backk(k,xnou,ynou);
                a[ xnou ][ ynou ] = 0;
                k--;
                use[ xnou ][ ynou ]= 0;
            }
        }

    }
}



int main()
{
    cin >> n;
    Backk(1, 1, 1);
    //Backk(1, 3, 3); - PLECARI DIN MIJLOCUL TABLEI
    cout << sol;
}
