#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll a, b;
void solve(){

}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("vannghe.inp","r",stdin);
    freopen("vannghe.out","w",stdout);
    cin>>a>>b;
    ll u = __gcd(a, b);
    cout<<u<<'\n'<<a/u<<" "<<b/u;
    //solve();
}