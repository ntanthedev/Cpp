//created in 2024-08-27-13.11.23 in Code::Blocks 20.03
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
const int MOD = 1e9 + 7;

int n, m;
long long w[N], dp[N][102];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> w[i];

    if(!w[1])
        for(int i = 1; i <= m; i++)
            dp[1][i] = 1;
    else
        dp[1][w[1]] = 1;

    for(int i = 1; i <= n; i++) {
        if(w[i]) {
            dp[i][w[i]] += dp[i - 1][w[i] - 1] + dp[i - 1][w[i]] + dp[i - 1][w[i] + 1];
            dp[i][w[i]] %= MOD;
        }
        else {
            for(int j = 1; j <= m; j++)
                dp[i][j] += (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
        }
    }

    long long ans = 0;
    for(int i = 1; i <= m; i++)
        ans += dp[n][i];
    ans %= MOD;
    cout << ans;
}
/*

*/
