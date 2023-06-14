#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 10;
const long long N = 1e6+9;
ll sqr(ll x){
    return x*x;
}
ll tpow(ll a, ll b){
    if(b == 0){
        return 1 % R;
    }
    else{
        if(b%2 == 0)
            return sqr(tpow(a,b/2))%R;
        else
            return a*(sqr(tpow(a,b/2))%R)%R;
    }
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("bai2_10_thithu4.inp","r",stdin);
    freopen("bai2_10_thithu4.out","w",stdout);
    ll a, b;
    cin>>a>>b;
    ll t = tpow(a, b);
    cout<<t;
}