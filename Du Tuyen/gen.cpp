#include <bits/stdc++.h>

using namespace std;
void solve() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    a = ' ' + a;
    b = ' ' + b;

    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(m + 1, {0, 0}));
    vector<vector<vector<char>>> res(n + 1, vector<vector<char>>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {

            if (a[i] == b[j]) {
                if (dp[i][j].first == 0) dp[i][j].second = (a[i] - '0');
                dp[i][j].first = dp[i - 1][j - 1].first + 1;
                res[i][j] = res[i - 1][j - 1];
                res[i][j].push_back(a[i]);
            }else {

                if (dp[i - 1][j].first > dp[i][j - 1].first) {
                    res[i][j] = res[i - 1][j];
                }else if (dp[i - 1][j].first == dp[i][j - 1].first) {

                    if (dp[i - 1][j].second > dp[i][j - 1].second) {
                        if (i == 6 &&j == 6) cout << ":D";
                        res[i][j] = res[i - 1][j];
                    }else res[i][j] = res[i][j - 1];
                }else {

                    res[i][j] = res[i][j - 1];
                }
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

    }

    cout << dp[n][m].first <<' ' << dp[6][5].second <<' ' << dp[5][6].second << '\n';
    for (auto it : res[5][5]) {
        cout << it;
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    solve();
}
