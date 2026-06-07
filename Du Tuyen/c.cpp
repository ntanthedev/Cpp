#include <bits/stdc++.h>
using namespace std;
long long a[1000006], b[1000006], dp[105][100005], cnt[105][100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= k; i++)
        cin >> b[i];

    long long INF = 1e18;

    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = -INF;
            cnt[i][j] = 0;
        }
    }

    for(int j = 0; j <= n; j++) {
        dp[0][j] = 0;
        cnt[0][j] = 1;
    }

    long long mod = 1e9 + 7;

    for(int i = 1; i <= k; i++) {
        for(int j = i; j <= n; j++) {
            if(dp[i][j - 1] > dp[i - 1][j - 1] + b[i] * a[j]) {
                dp[i][j] = dp[i][j - 1];
                cnt[i][j] = cnt[i][j - 1];
            } else if(dp[i][j - 1] < dp[i - 1][j - 1] + b[i] * a[j]) {
                dp[i][j] = dp[i - 1][j - 1] + b[i] * a[j];
                cnt[i][j] = cnt[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
                cnt[i][j] = (cnt[i][j - 1] + cnt[i - 1][j - 1]) % mod;
            }
        }
    }

    cout << dp[k][n] << '\n' << cnt[k][n];
}