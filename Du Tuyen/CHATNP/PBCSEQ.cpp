#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define xau "a"
#define fi first
#define se second
#define ii pair<int, int>
const int N = 2e6 + 9;
using namespace std;
typedef long long ll;
ll t, f[N];
ii a[N];
template<typename T>
inline void read(T& x) {
    bool b = 0;
    char c;
    while(!isdigit(c = getchar()) && c != '-')
        ;
    if(c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while(isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if(b) {
        x = -x;
    }
}
bool cmp(ii a, ii b) {
    return a.fi < b.fi || (a.fi == b.fi && a.se > b.se);
}
void solve() {
    ll n, m = 1;
    read(n);
    for(int i = 1; i <= n; i++)
        read(a[i].fi), read(a[i].se);
    sort(a + 1, a + 1 + n, cmp);
    // for(int i = 1; i <= n; i++) cout<<a[i].fi<<" "<<a[i].se<<"||";
    f[1] = a[n].se;
    for(int i = n - 1; i >= 1; i--) {
        if(a[i].se >= f[m])
            f[++m] = a[i].se;
        else if(a[i].se < f[1])
            f[1] = a[i].se;
        else {
            ll t = upper_bound(f + 1, f + m + 1, a[i].se) - f;
            f[t] = a[i].se;
        }
    }
    // cout<<'\n';
    cout << m << '\n';
}
#define task "PBCSEQ"
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    t = 1;
    while(t--)
        solve();
}
