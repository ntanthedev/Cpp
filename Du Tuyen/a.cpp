#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    a = ' ' + a;
    b = ' ' + b;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {

            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[1][min(n, m)];
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    solve();
}
