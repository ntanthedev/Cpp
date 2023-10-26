#include<bits/stdc++.h>
#define ll long long
#define xau "DEM"
const int N = 1e6+9;
using namespace std;
unordered_map<ll, ll> M;
ll n, s[N], ans = 0, x, a[N];
ll read(){
    bool neg = false;
    char c = getchar();
    for(; c < '0' || '9' < c; c = getchar())
        if(neg == '-')
            neg = !neg;
    ll k = 0;
    while('0' <= c && c <= '9')
        k = (k << 3) + (k << 1) + c - '0', c = getchar();
    return neg ? -k : k;
}
void solve(){
    M[0] = 1;
    for(int i = 1; i <= n; i++){
        ans += M[s[i]];
        M[s[i]%n]++;
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(xau".inp","r")){
        freopen(xau".inp","r",stdin);
        freopen(xau".out","w",stdout);
    }
    else{
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    n = read(); s[0] = 0;
    for(int i = 1; i <= n; i++){
        x = read();
        x = x%n;
        s[i] = s[i-1] + x;
        s[i] = s[i]%n;
        //cout<<s[i]<<" ";
    }
    solve();
}
