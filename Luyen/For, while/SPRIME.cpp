#include<bits/stdc++.h>
using namespace std;
bool nt(long long x)
{
    if (x < 2)
        return 0;
    for(int i = 2; i <= sqrt(x); i ++)
        if(x % i == 0)
            return 0;
    return 1;
}
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("SPRIME.inp");
    xuat.open("SPRIME.out");
    long long i = 2, n, tong = 0;
    doc>>n;
    while (i <= n)
    {
        if(nt(i) == 1)
            tong += i;
        i++;
    }
    if(nt(tong) == 1)
    {
        xuat<<tong<<endl;
        xuat<<"YES";
    }
    else
        xuat<<"NO";
    doc.close();
    xuat.close();
}
