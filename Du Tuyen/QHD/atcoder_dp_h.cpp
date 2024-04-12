// problem "atcoder_dp_h"
// created in 14:03:53 - Fri 12/04/2024

#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, mod = 1e9 + 7;
    
    cin >> m >> n;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[1][1] = 1;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if(c == '#')
                continue;
            dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }

    cout << dp[m][n];
}