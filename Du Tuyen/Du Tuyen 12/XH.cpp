//problem "XH"
//created in 08:37:23 - Mon 22/07/2024

#include<bits/stdc++.h>

#define int int64_t
#define fi first 
#define se second

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "XH"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }   

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> c(m);
    vector<tuple<int, int, int>> s(n);

    for(auto& [x, y, z] : s)
        cin >> x >> y >> z;
    for(auto& [r, h] : c)
        cin >> r >> h;

    if(n == 0) {
        sort(c.begin(), c.end(), greater<pair<int, int>>());
        
        vector<int> dp(m, 0);
        int ans = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(c[j].fi <= c[i].fi) {
                    dp[j] = max(dp[j], dp[i] + c[j].se);
                }
            }
            ans = max(ans, dp[i]);
        }

        cout << ans ;
    }
}