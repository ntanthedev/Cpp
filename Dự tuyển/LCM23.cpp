#include<bits/stdc++.h>
#define ll long long
#define xau "LCM23"
const int N = 1e6+9;
using namespace std;
ll a, b, c, d;
unsigned ll lcm(ll x, ll y){
    return x*y/(__gcd(x, y));
}
void solve(){
    cout<<lcm(lcm(a,b), lcm(c, d));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(xau".inp","r")){
        freopen(xau".inp","r",stdin);
        freopen(xau".out","w",stdout);
    }
    cin >> a >> b >> c >> d;
    solve();
}
