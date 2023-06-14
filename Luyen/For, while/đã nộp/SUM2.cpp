#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long a, Tong = 0;
    cin>>a;
    while(a>=1)
    {
        Tong += a;
        a -= 1;
    }
    cout<<Tong;
}
