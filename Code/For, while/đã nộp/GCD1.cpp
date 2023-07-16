#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("GCD1.inp");
    xuat.open("GCD1.out");
    unsigned long long a, b, dem = 0, i = 1, m;
    doc>>a>>b;
    m = a > b ? b : a; //a = min(a,b)
    while(i <= m )
    {
        if(a%i == 0 && b%i == 0)
        {
            dem = dem + 1;
        }
        i++;
    }
    xuat<<dem;
    doc.close();
    xuat.close();

}
