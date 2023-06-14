#include<bits/stdc++.h>
using namespace std;
unsigned long long n, x, m, l, s;
int sqr(long long x) {
    return x*x;
}
int pow(long long a, long long b, long long MOD) {
    if (b == 0) return 1 % MOD;
    else
        if (b % 2 == 0)
            return sqr(pow(a, b/2)) % MOD;
        else
            return a * (sqr(pow(a, b/2)) % MOD) % MOD;
}
int main()
{
    cin.tie(NULL);
    freopen("POWER5.inp","r",stdin);
    freopen("POWER5.out","w",stdout);
    cin>>x>>n>>m;
    cout<<pow(x,n,m);
}
