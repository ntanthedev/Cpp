//problem "a"
//created in 10:24:41 - Wed 04/12/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    auto b = a;

    reverse(b.begin() + 1, b.end());

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

    cout << n - dp[n][n];
}