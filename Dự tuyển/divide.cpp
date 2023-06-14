#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll T;
ll lcm(ll a, ll b){
    return (a*b)/__gcd(a, b);
}
void solve(){
    ll ans, a, b, c, n;
    cin >> n >> a >> b >> c;
    ll gab, gac, gbc, gabc;
    ans = n/a + n/b + n/c;
    gab = lcm(a, b);
    gac = lcm(a, c);
    gbc = lcm(b, c);
    gabc = lcm(gab, lcm(gac, gbc));
    if(gab == gac)
        gab = n+1;
    if(gbc == gac)
        gbc = n+1;
    if(gab == gbc)
        gab = n+1;
    cout<<ans - n/gabc - n/gab - n/gac - n/gbc<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen("divide.inp","r")){
        freopen("divide.inp","r",stdin);
        freopen("divide.out","w",stdout);
    }else{
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    cin >> T;
    while(T--)
        solve();
}

