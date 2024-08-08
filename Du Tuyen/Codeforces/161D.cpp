//problem "161D"
//created in 22:59:33 - Wed 07/08/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k, ans = 0;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    vector<vector<int>> dq(n + 1, vector<int>(k + 1, 0));

    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<void(int, int)> dfs = [&] (int u, int p) {
        dp[u][0] = 1;
        for(auto v : adj[u]) {
            if(v == p) continue;
            dfs(v, u);
            for(int i = 1; i <= k; i++)
                dp[u][i] += dp[v][i - 1];
        }
        ans += dp[u][k];
    };

    dfs(1, 0);

    // cerr << "ans after dfs " << ans << '\n';

    function<void(int, int)> dfs2 = [&] (int u, int p) {
        dq[u][0] = 1;

        if(u != 1) {
            dq[u][1] = 1;
            for(int i = 2; i <= k; i++) {
                dq[u][i] += dp[p][i - 1] - dp[u][i - 2];
                dq[u][i] += dq[p][i - 1];
            }
        }
        // dbg(u)
        // dbg(dp[u])
        // dbg(dq[u])

        for(auto v : adj[u]) {
            if(v == p) continue;
            dfs2(v, u);
        }

        ans += dq[u][k];
    };

    dfs2(1, 0);

    cout << ans / 2;
}
