#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long Tong = 0, a = 1, x, c;
    cin>>x;
    while( a<=x )
    {
        Tong += (a*a);
        a++;
    }
    c = Tong%2020;
    cout<< c;
}
