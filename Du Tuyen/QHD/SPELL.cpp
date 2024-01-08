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
    vector<vector<vector<int>>> ans(n + 2, vector<vector<int>>(m + 2, vector<int>(k + 2, 1e9)));
    for (int c = 1; c <= k; ++c) {
                    for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    int a1 = dp[i + 1][j][c - 1], a2 = dp[i - 1][j][c - 1], a3 = dp[i][j + 1][c - 1], a4 = dp[i][j - 1][c - 1]; 
                    if (a1 < c - 1) a1 = 1e9;
                    if (a2 < c - 1) a2 = 1e9;
                    if (a3 < c - 1) a3 = 1e9;
                    if (a4 < c - 1) a4 = 1e9;
                    dp[i][j][c - 1] = min(min({a1, a2, a3, a4}) + 1, dp[i][j][c - 1]);
                }
            }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i][j] == s[1] && c == 1) dp[i][j][c] = 1;
                else {                  
                      int a1 = dp[i + 1][j][c - 1], a2 = dp[i - 1][j][c - 1], a3 = dp[i][j + 1][c - 1], a4 = dp[i][j - 1][c - 1]; 
                    if (a1 < c - 1) a1 = 1e9;
                    if (a2 < c - 1) a2 = 1e9;
                    if (a3 < c - 1) a3 = 1e9;
                    if (a4 < c - 1) a4 = 1e9;
                    dp[i][j][c] = min({a1, a2, a3, a4}) + 1;
                    ans[i][j][c] = dp[i][j][c];
                    
                }
            }
        }
        if(c==k)break;
        }

    
    int res = 1e9;
    cout << dp[1][3][2] << '\n';
    cout << dp[1][2][3] << '\n';
    cout << dp[2][3][3] << '\n';
    cout << dp[1][4][3] << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == s[k]) {
                cout << i <<" " << j <<" " << ans[i][j][k] << '\n';
                res = min(res, ans[i][j][k]);
            }
        }
    }
    cout << res;

}