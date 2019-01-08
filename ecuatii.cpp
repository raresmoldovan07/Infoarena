#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream fin("ecuatii.in");
    ofstream fout("ecuatii.out");
    char s[258],ec1[258],ec2[258],semn;
    int num[1000], nec[1000];
    char *pch;
    long long n,val,valnec,valnec1,val1;
    fin >> n;
    fin.getline(s,1);
    for(int k = 1; k <= n; ++k)
    {
        val = 0;
        val1 = 0;
        valnec1 = 0;
        valnec = 0;
        fin.getline(s,255);
        pch = strtok(s,"=");
        strcpy(ec1,pch);
        pch = strtok(NULL," ");
        strcpy(ec2,pch);
        int nr = 0;
        semn = '+';
        for(int i = 0; i < strlen(ec1); ++i)
        {

            if(ec1[i] >= '0' && ec1[i]<='9')
                nr = nr*10 + (ec1[i]-48);
            else if(ec1[i]=='x' && nr > 0 )
                if(semn == '+')valnec += nr, nr = 0;
                else valnec -= nr, nr = 0;
            else if(ec1[i] == 'x' && nr==0)
                if(semn == '+')valnec++;
                else valnec--;
            else
            {
                if(semn == '+' && ec1[i-1] !='x')
                    val = val + nr, nr = 0;
                else if(semn == '-' && ec1[i-1] != 'x')
                    val = val - nr, nr = 0;
                semn  = ec1[i];
            }


        }
        if(ec1[strlen(ec1)] == 'x')
            if(semn == '-') valnec -= nr;
            else valnec += nr;
        else {
            if(semn == '+') val += nr;
            else val -=  nr;
        }
        nr = 0;
        semn = '+';
        for(int i = 0; i < strlen(ec2); ++i)
        {

            if(ec2[i] >= '0' && ec2[i]<='9')
                nr = nr*10 + (ec2[i]-48);
            else if(ec2[i]=='x' && nr > 0 )
                if(semn == '+')valnec1 += nr, nr = 0;
                else valnec1 -= nr, nr = 0;
            else if(ec2[i] == 'x' && nr==0)
                if(semn == '+')valnec1++;
                else valnec1--;
            else
            {
                if(semn == '+' && ec2[i-1] !='x')
                    val1 = val1 + nr, nr = 0;
                else if(semn == '-' && ec2[i-1] != 'x')
                    val1 = val1 - nr, nr = 0;
                semn  = ec2[i];
            }


        }
        if(ec2[strlen(ec2)] == 'x')
            if(semn == '-') valnec1 -= nr;
            else valnec += nr;
        else {
            if(semn == '+') val1 += nr;
            else val -=  nr;
        }
        float sol;
        if(val1-val == 0 && valnec-valnec1 == 0)
           fout<<"infinit"<<'\n';
        else if(valnec-valnec1 == 0)
            fout<<"imposibil"<<'\n';
        else {
            sol = (float)(val1-val)/(valnec-valnec1);
            fout<<fixed<<setprecision(4)<<sol<<'\n';
        }
    }
}
