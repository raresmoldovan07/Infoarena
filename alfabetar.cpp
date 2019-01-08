#include <fstream>
#include <string.h>

using namespace std;

char s[101][255];
int maxx = 0 , n;
ifstream fin("alfabetar.in");
ofstream fout("alfabetar.out");

void Read()
{
    fin >> n;
    for(int i = 0; i <= n; ++i)
        fin.getline(s[i], 200);
}

void maxim()
{
    for(int i = 1;i <= n; ++i)
        if(strlen(s[i])>maxx)
            maxx = strlen(s[i]);
}



int main()
{
    Read();
    maxim();
    for(int i = 1; i <= maxx; ++i)
    {

        for(int j = 1; j <= n; ++j)
        {
            if((s[j][maxx-i]>=65&&s[j][maxx-i]<=90) || (s[j][maxx-i]>=97&&s[j][maxx-i]<=122) || (s[j][maxx-i]>='0'&&s[j][maxx-i]<='9'))
               fout<<s[j][maxx-i];
               else fout<<' ';
        }
        fout<<endl;
    }
}
