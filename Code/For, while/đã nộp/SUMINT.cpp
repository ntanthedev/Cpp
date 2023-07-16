#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("SUMINT.inp");
    xuat.open("SUMINT.out");
    long long a, b, i = 1, tong = 0, tongchan = 0;
    doc>>a>>b;
    while (a <= b)
    {
        if(a%2 == 0)
        {
            tongchan += a;
        }
        tong += a;
        a
        ++;
    }
    xuat<<tong<<endl;
    xuat<<tongchan<<endl;
    doc.close();
    xuat.close();
}
