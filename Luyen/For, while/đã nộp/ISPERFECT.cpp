#include<bits/stdc++.h>
using namespace std                                 ;
int main ()
{
    ifstream doc                                    ;
    ofstream xuat                                   ;
    doc.open("ISPERFECT.inp")                       ;
    xuat.open("ISPERFECT.out")                      ;
    unsigned long long n, i = 1, tong = 0           ;
    doc>>n                                          ;
    while( i < n)
    {
        if(n%i == 0)
        {
            tong += i                               ;
        }
        i++                                         ;
    }
    if(tong == n)
        xuat<<"YES"                                 ;
    else
        xuat<<"NO"                                  ;
    doc.close()                                     ;
    xuat.close()                                    ;
}
