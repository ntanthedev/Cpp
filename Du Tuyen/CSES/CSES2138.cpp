//problem "CSES2138"
//created in 15:24:27 - Mon 22/07/2024

#include<bits/stdc++.h>

#define int int64_t
const int N = 5 * 1e4 + 5;

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    

    int n, m;
    cin >> n >> m;

    bitset<N> f[n + 2];
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<bool> visit(n + 1, false);

    for(int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    function<void(int)> dfs = [&](int u) {
        f[u].set(u);
        visit[u] = 1;
        for(auto v : adj[u]) {
            if(!visit[v])
                dfs(v);
            f[u] |= f[v];
        }
    };

    for(int i = 1; i <= n; i++) {
        if(!f[i].count())
            dfs(i);
        cout << f[i].count() << " ";
    }
}