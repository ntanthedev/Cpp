#include<bits/stdc++.h>

#define int int64_t
#define w first
#define v second

using namespace std;

int n, W;
pair<int, int> a[102];
int dp[102][100002];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> W;
    for(int i = 1; i <= n; i++) 
        cin >> a[i].w >> a[i].v;
    
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {
            if(j - a[i].w >= 0)
                dp[i][j] = max(dp[i-1][j-a[i].w] + a[i].v, dp[i-1][j]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    
    cout << dp[n][W];
}