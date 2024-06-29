//template simple for codeforces by ntannn_
//created in 18:38:02 - Fri 28/06/2024
#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> num(n + 1, 0), low(n + 1), f(n + 1, 0);
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timedfs = 0, ans = n * (n - 1) / 2;
    function<void(int, int)> dfs = [&](int u, int p) {
        low[u] = num[u] = ++timedfs;

        f[u] = 1;

        for(auto v : adj[u]) {
            if(v == p) continue;;

            if(!num[v])
                dfs(v, u),
                low[u] = min(low[u], low[v]),
                f[u] += f[v];
            else
                low[u] = min(low[u], num[v]);
        }

        if(low[u] == num[u] && u != 1) {
            int a = f[u], b = n - f[u];

            ans = min(ans, a * (a - 1) / 2 + b * (b - 1) / 2);
        }
    };

    dfs(1, 0);

    cout << ans;    
}

int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case;
    for(cin >> test_case;test_case--;cout << '\n') 
        solve();
}