#include <bits/stdc++.h>

#define int int64_t
#define w first
#define v second

using namespace std;

int n, W, V = 0;
pair<int, int> a[102];
int dp[102][100002];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> W;
    for(int i = 1; i <= n; i++)
        cin >> a[i].w >> a[i].v, V += a[i].v;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= V; j++)
            dp[i][j] = W + 1;
        dp[i][0] = 0;
        dp[i][a[i].v] = a[i].w;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= V; j++) {
            if(j >= a[i].v)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - a[i].v] + a[i].w);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int ans = 0;
    for(int i = 1; i <= V; i++)
        if(dp[n][i] <= W)
            ans = i;

    cout << ans;
}