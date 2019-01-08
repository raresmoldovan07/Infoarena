#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

unsigned int a[1000], b[1000], p[1000], c[100000];

void show()
{
    for(int i = a[0]; i >= 1; --i)
        cout << a[i];
    cout<<endl;
    for(int i = b[0]; i >= 1; --i)
        cout<<b[i];
}

void add(int A[], int B[])
{
      int i, t = 0;
      int C[1000];
      for (i=1; i<=A[0] || i<=B[0] || t; i++, t/=10)
              C[i] = (t += A[i] + B[i]) % 10;
      C[0] = i - 1;
      for(int i = C[0]; i >= 1;-- i)
        cout << C[i];
}

void mul(int A[], int B)
{
      int i, t = 0;
      for (i = 1; i <= A[0] || t; i++, t /= 10)
              A[i] = (t += A[i] * B) % 10;
      A[0] = i - 1;
}

void mul2(unsigned int A[], unsigned int B[])
{
      int i, j, t, C[1000];

      for (i = 1; i <= A[0]; i++)
      {
              for (t=0, j=1; j <= B[0] || t; j++, t/=10)
                      C[i+j-1]= (t+=C[i+j-1]+A[i]*B[j]) %10;
              if (i + j - 2 > C[0]) C[0] = i + j - 2;
      }

      for(int i = C[0]; i >= 1;-- i)
        cout << C[i];
}

int main()
{
    char s[1000];
    cin >> s;
    a[0] = strlen(s);
    for(int i = 0; i < strlen(s); ++i)
    {
        a[a[0]-i] = s[i] - 48;
    }
    cin >> s;
    b[0] = strlen(s);
    for(int i = 0; i < strlen(s); ++i)
    {
        b[b[0]-i] = s[i] - 48;
    }
    mul2(a,b);
}
