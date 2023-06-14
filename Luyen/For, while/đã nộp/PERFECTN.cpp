#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("PERFECTN.inp");
    xuat.open("PERFECTN.out");
    unsigned long long n, S;
    doc>>n;
    for(int i = 1; i <= n; i++)
    {
        S = 0;
        for(int j = 1; j < i; j++)
        {
            if(i%j == 0)
            {
                S += j;
            }

        }
        if(S == i)
            xuat<<i<<" ";
    }
    doc.close();
    xuat.close();

}


