#include<bits/stdc++.h>
using namespace std;
unsigned long long a, b, u;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("PS.inp","r",stdin);
    freopen("PS.out","w",stdout);
    cin>>a>>b;
    u = __gcd(a,b);
    cout<<a/u<<" "<<b/u;
}
