#include<bits/stdc++.h>
using namespace std;
bool fb(long long x)
{
    long long f1 = 0, f2 = 1, i = 0;
    while(i <= x)
    {
        i = f1 + f2;
        f1 = f2;
        f2 = i;
    }
    if(i != x)
        return 0;

    return 1;
}
int main ()
{
    long long n, x;
    cin>>n;
    x = n;
    while(fb(x) == 0) x--;
    cout<<x;
}
