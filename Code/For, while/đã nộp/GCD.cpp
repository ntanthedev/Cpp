#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("GCD.inp");
    xuat.open("GCD.out");
    unsigned long long a, b, r;
    doc>>a>>b;
    while(b != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    xuat<<a;
    doc.close();
    xuat.close();

}
