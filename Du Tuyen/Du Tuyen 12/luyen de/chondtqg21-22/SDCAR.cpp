#include<bits/stdc++.h>

using namespace std;

int n, m, br;
const int MOD = 1e9 + 7;
vector<vector<int>> dp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("SDCAR.inp","r",stdin);
    freopen("SDCAR.out","w",stdout);

    cin >> m >> n >> br;

    dp.resize(m + 2, vector<int>(n + 2));

    for(int i = 1, x, y; i <= br; i++) {
        cin >> x >> y;
        dp[x][y] = -1;
    }

    dp[1][0] = 1;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(dp[i][j] == -1)
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;

    cout << dp[m][n];
}
