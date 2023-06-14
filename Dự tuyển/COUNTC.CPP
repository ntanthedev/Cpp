#include<bits/stdc++.h>
#define ll long long
#define ii pair<long long, long long>
#define fi first
#define se second
#define xau "COUNTC"
const int N = 1e6+9;
using namespace std;
ll n, ans = 0;
ll a[N], b[N], c[N], b2[N], a1[N];
ii b1[N];
ll read(){
    bool neg = false;
    char c = getchar();
    for(; c < '0' || '9' < c; c = getchar())
        if(c == '-') neg = !neg;
    ll k = 0;
    while('0' <= c && c <= '9')
        k = (k << 3) + (k << 1) + c - '0', c = getchar();
    return neg ? -k : k;
}
void solve(){
    sort(c+1, c+1+n);
    sort(b+1, b+1+n);
    ll m = 0;
    for(int i = 1; i <= n; i++){
        ll t = upper_bound(c+1, c+1+n, b[i]) - c;
        ll sl = n - t + 1;
        if(sl > 0){
            b1[++m].first = b[i];
            b1[m].second = sl;
        }
    }
    sort(b1+1, b1+m+1);
    memset(b, 0, sizeof(b));
    b[0] = 0;
    for(int i = 1; i <= m; i++){
        b2[i] = b1[i].first;
        b[i] = b[i-1] + b1[i].second;
    }
    for(int i = 1; i <= n; i++){
        ll t = upper_bound(b2+1, b2+1+m, a[i]) - b2 - 1;
        ans += b[m] - b[t];
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
    n = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= n; i++) b[i] = read();
    for(int i = 1; i <= n; i++) c[i] = read();
    solve();
}
