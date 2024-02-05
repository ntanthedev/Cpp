#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, a[N], b[N], dp[1005][1005], f[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (abs(a[i] - b[j]) <= 4) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][n];

}
int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    solve();

}