#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll a, b, c, d;
void solve(){
    ll lc, ld, lbc, bc;
    lc = b/c - a/c;
    if(a%c == 0)
        lc++;
    ld = b/d - a/d;
    if(a%d == 0)
        ld++;
    bc = c*d/(__gcd(c, d));
    lbc = b/bc - a/bc;
    if(a%bc == 0)
        lbc++;
    cout<<lc + ld - lbc;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("Bai1_10_2021_2022.inp","r",stdin);
    freopen("Bai1_10_2021_2022.out","w",stdout);
    cin >> a >> b >> c >> d;
    solve();
}
