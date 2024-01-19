#include<bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #define task "LCS1"
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    vector<vector<vector<char>>> dp(n+1, vector<vector<char>>(m+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1];
                dp[i][j].push_back(a[i]);
            }
            else {
                dp[i][j] = (dp[i-1][j].size() > dp[i][j-1].size() ? dp[i-1][j] : dp[i][j-1]);
            }
        }
    }
    for(auto i : dp[n][m])
        cout << i ;
}