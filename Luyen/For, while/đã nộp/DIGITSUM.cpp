#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("DIGITSUM.inp");
    xuat.open("DIGITSUM.out");
    unsigned long long n, d, Tong = 0;
    doc>>n;
    for(;n > 0;n /= 10)
    {
        d = n%10;
        Tong += d;
    }
    xuat<<Tong;
    doc.close();
    xuat.close();
}
