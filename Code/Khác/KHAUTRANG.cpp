#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("KHAUTRANG.inp");
    xuat.open("KHAUTRANG.out");
    int n, t;
    doc>>n;
    if(n <= 3)
        t = 4500;
    else if (n >= 4 && n <= 10)
        t = 4000;
    else
        t = 3800;
    xuat<<n*t;
    doc.close();
    xuat.close();
}
