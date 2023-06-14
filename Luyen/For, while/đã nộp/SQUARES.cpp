#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("SQUARES.inp");
    xuat.open("SQUARES.out");
    unsigned long long n, i = 1, S = 0;
    doc>>n;
    while(i <= n)
    {
        S += i*i;
        i++;
    }
    xuat<<S%2013;
    doc.close();
    xuat.close();
}
