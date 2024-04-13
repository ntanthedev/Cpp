// problem "atcoder_dp_i"
// created in 14:27:21 - Fri 12/04/2024

#include <bits/stdc++.h>

using namespace std;

int n, k;
long double dp[3001][3001], p[3000];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];

    k = n / 2 + 1;

    dp[1][0] = 1 - p[1];
    dp[1][1] = p[1];

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            dp[i][j] = dp[i - 1][j] * double(1 - p[i]);
            if(j > 0)
                dp[i][j] += dp[i - 1][j - 1] * p[i];
            // else
            //     dp[i][j] += dp[i-1][j] * p[i]; 
        }
    }

    double ans = 0;
    for(int i = n; i >= k; i--) 
        ans += dp[n][i];

    cout << fixed << setprecision(10) << ans;
}