//problem "atcoder_dp_f"
//created in 09:21:55 - Fri 12/04/2024

#include<bits/stdc++.h>

// #define int int64_t

using namespace std;
string a, b;
vector<vector<int>> dp(3003, vector<int>(3003, 0)), trace(3003, vector<int>(3003, 0));

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = ' ' + a;
    b = ' ' + b;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                trace[i][j] = dp[i-1][j] > dp[i][j-1] ? trace[i-1][j] : trace[i][j-1]; 
            }
        }
    }

    string ans;
    
    while(n && m) {
        if(a[n] == b[m]) {
            ans.push_back(a[n]);
            n--, m--;
        }
        else if(dp[n][m-1] < dp[n-1][m])
            n--;
        else 
            m--;
    }

    reverse(ans.begin(), ans.end());
    cout << ans;    
}