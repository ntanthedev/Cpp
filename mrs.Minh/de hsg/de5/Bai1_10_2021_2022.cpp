#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll a, b, c, d, ucln, bcnn, dc, dd, ds;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai1_10_2021_2022.inp","r",stdin);
    freopen("Bai1_10_2021_2022.out","w",stdout);
    cin>>a>>b>>c>>d;
    ucln = __gcd(c, d);
    bcnn = (c*d)/ucln;
    dc = b/c - a/c;
    dd = b/d - a/d;
    ds = b/bcnn - a/bcnn;
    ll ans;
    ans = dc + dd - ds;
    cout<<ans; 
}