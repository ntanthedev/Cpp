#include<bits/stdc++.h>
#define tag "lis2vn"
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define po pop_back
#define ll long long 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
using namespace std;
ll n, m = 1;
ii a[N], b[N];
ll read(){
    bool neg = false;
    char c = getchar();
    for(; c < '0' || '9' < c; c = getchar())
        if(c =='-') neg = !neg;
    ll k = 0;
    while('0' <= c && c <= '9')
        k = (k << 3) + (k << 1) + c - '0', c = getchar();
    return neg ? -k : k;
}
bool cmp(ii x, ii y){
    return x.fi < y.fi || (x.fi == y.fi && x.se > y.se);
}
void solve(){
    //sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= n; i++)
        ll t = lower_bound(b+1, b+1+m, ii(a[i].fi, a[i].se)) - b;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    n = read();
    for(int i = 1; i <= n; i++){
        a[i].fi = read();
        a[i].se = read();
    }
    solve();
}