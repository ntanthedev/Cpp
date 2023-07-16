#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("ISPRIME.inp");
    xuat.open("ISPRIME.out");
    unsigned long long n, kt = 1, i = 2 ;
    doc>>n;
    if(n == 0 || n == 1)
        xuat<<"NO";
    while(i <= sqrt(n))
    {

        if(n%i == 0)
        {
            kt = 0;
            break;
        }
            i++;
    }
    if(kt == 0)
        xuat<<"NO";
    else
        xuat<<"YES";
    doc.close();
    xuat.close();
    return 0;
}
