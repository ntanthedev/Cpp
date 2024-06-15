#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second 
typedef long long ll;
void solve()
{
    ll m,d,w;
    cin>>m>>d>>w;
    ll g=__gcd(d-1,w);
    w/=g;
    if(m<d) swap(m,d);
    ll ans=0;
    ll mod1=m%w,mod2=d%w;
    ans+=min(mod1,mod2)*((d/w)*(d/w + 1)/2 + (((m - m%d)-(d - d%w))/w)*(d/w + 1));
    if(mod1>=mod2) 
    {
        ans+=(mod1-mod2)*
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tests;
    cin>>tests;
    while(tests--)
    {
        solve();
        cout<<'\n';
    }
}