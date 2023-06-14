#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("CPRIME.inp");
    xuat.open("CPRIME.out");
    long n, t = 0, kt;
    doc>>n;
    for(int i = 2; i <= n; i++)
    {
        kt = 0;
        for(int j = 2; j <= sqrt(i); j++)
        {
            if(i%j == 0)
            {
                kt = 1;
                break;
            }

        }
        if(kt == 0)
            t = t + 1;
    }
    xuat<<t;
    doc.close();
    xuat.close();
}
