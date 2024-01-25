#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
using namespace std;
typedef long long ll;

template<typename T> inline void read(T& x) {
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

void solve() {
    ll m, n, ans = 0;
    read(m), read(n);
    vector<vector<ll>> a(m + 1, vector<ll>(n + 1)),
        pre(m + 2, vector<ll>(n + 2));
    vector<pair<ll, ll>> point(n + 1, {1 * 1ll, 1 * 1ll});
    ll k;
    read(k);
    for(ll i = 1; i <= m; i++) {
        vector<ll> pree(n + 1);
        for(ll j = 1; j <= n; j++) {
            read(a[i][j]);
            pree[j] = pree[j - 1] + a[i][j];
            pre[i][j] = pree[j] + pre[i - 1][j];
            point[j].fi = 1, point[j].se = 1;
            while(point[j].se <= j && point[j].fi <= i) {
                if((pre[i][j] - pre[i][point[j].se - 1] -
                    pre[point[j].fi - 1][j] +
                    pre[point[j].fi - 1][point[j].se - 1]) <= k) {
                    ans =
                        max(ans, (i - point[j].fi + 1) * (j - point[j].se + 1));
                }
                point[j].se++;
                if(point[j].se > j) {
                    point[j].se = 1;
                    point[j].fi++;
                }
            }
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("LAND.inp", "r")) {
        freopen("LAND.inp", "r", stdin);
        freopen("LAND.out", "w", stdout);
    }
    solve();
}