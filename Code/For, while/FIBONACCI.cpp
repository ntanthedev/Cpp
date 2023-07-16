#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("FIBONACCI.inp");
    xuat.open("FIBONACCI.out");
    long long n, f1 = 1, f2 = 1, f3;
    doc>>n;
    while(f3 <= n)
    {
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }
    if(f3 = n)
        xuat<<f3;
    else
        xuat<<f2;
    doc.close();
    xuat.close();
}
