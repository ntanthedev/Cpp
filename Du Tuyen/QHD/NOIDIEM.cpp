#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void solve() {
    ll n, k, S = 0;
    cin >> n >> k;
    vector<ll> a(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            if(abs(a[j] - i) <= k)
                dp[i][j]++;
            dp[i][j] = max({dp[i][j], dp[i][j - 1], dp[i - 1][j]});
        }
    }
    cout << dp[n][n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("NOIDIEM.inp", "r")) {
        freopen("NOIDIEM.inp", "r", stdin);
        freopen("NOIDIEM.out", "w", stdout);
    }
    solve();
}