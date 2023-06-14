#include<bits/stdc++.h>
using namespace std;

    bool nt(long long x)
    {
        if (x < 2) return 0;
        for(int i = 2; i <= sqrt(x); i++)
        if(x%i == 0) return 0;
        return 1;
    }
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("LPRIME.inp");
    xuat.open("LPRIME.out");
    unsigned long long n, x;
    doc>>n;
    x = n;
    while(nt(x) == 0) x--;
    xuat<<x;
    doc.close();
    xuat.close();
}
