#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll m, n;
void solve(){
    ll u = __gcd(m, n);
    cout<<u<<'\n'<<m/u<<" "<<n/u;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("VANNGHE.inp","r",stdin);
    freopen("VANNGHE.out","w",stdout);
    cin>>m>>n;
    solve();
}