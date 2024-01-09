#include<bits/stdc++.h>

using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n)), dp(m, vector<int>(n, 1));
    for(auto &i : a)
        for(auto &j : i)
            cin >> j;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == a[i][j-1])
                dp[i][j]++;
            }
        }
    }
}