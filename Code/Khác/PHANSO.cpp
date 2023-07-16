#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream doc;
    ofstream xuat;
    doc.open("PHANSO.INP");
    xuat.open("PHANSO.OUT");
    long long a, b, n, m, r;
    doc>>a>>b;
    n = a; m = b;
    r = n%m;
    while(r != 0)
    {
        n = m;
        m = r;
        r = n%m;
    }
    //luc nay ucln la m
    xuat<<a/m<<" "<<b/m;
    doc.close();
    xuat.close();


}
