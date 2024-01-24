#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
void solve() {
    ll m, n, ans = 0;
    cin >> m >> n;
    vector<vector<ll>> a(m + 1, vector<ll>(n + 1)),
        pre(m + 2, vector<ll>(n + 2));
    vector<pair<ll, ll>> point(n + 1, {1 * 1ll, 1 * 1ll});
    ll k;
    cin >> k;
    for(ll i = 1; i <= m; i++) {
        vector<ll> pree(n + 1);
        for(ll j = 1; j <= n; j++) {
            cin >> a[i][j];
            pree[j] = pree[j - 1] + a[i][j];
            pre[i][j] = pree[j] + pre[i - 1][j];
            // cout<<pre[i][j]<<" ";
            point[j].fi = 1, point[j].se = 1;
            while(point[j].se <= j && point[j].fi <= i) {
                // if((pre[i][j]-pre[point[j].fi+1][j])<=k)
                // ans=max(ans,(i-point[j].fi)*j);
                if((pre[i][j] - pre[i][point[j].se - 1] -
                    pre[point[j].fi - 1][j] +
                    pre[point[j].fi - 1][point[j].se - 1]) <= k) {
                    ans =
                        max(ans, (i - point[j].fi + 1) * (j - point[j].se + 1));
                    // cout<<i<<" "<<j<<" "<<point[j].fi<<" "<<point[j].se<<"
                    // "<<pre[i][j]-pre[point[j].fi][point[j].se-1]-pre[point[j].fi-1][j]<<'\n';
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