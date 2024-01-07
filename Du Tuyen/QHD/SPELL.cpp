#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; int n, m, k;
    char a[310][310];

    cin >> n >> m >> k;
    cin >> s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    s = " " + s;
    vector<vector<vector<int>>> dp(n + 2, vector<vector<int>>(m + 2, vector<int>(k + 2, 1e9)));
    for (int c = 1; c <= k; ++c) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i][j] == s[1] && c == 1) dp[i][j][c] = 1;
                else {
                    if (dp[i][j][c] = min ({dp[i - 1][j][c - 1], dp[i + 1][j][c - 1], dp[i][j - 1][c - 1], 1;


                    
                }
            }
        }

    }
    int ans = 1e9;
    cout << dp[1][1][3] << '\n';
    cout << dp[2][1][3] << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == s[k]) ans = min(ans, dp[i][j][k]);
        }
    }
    cout << ans;

}