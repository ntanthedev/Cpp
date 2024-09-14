//code by ntannn
#include<bits/stdc++.h>

using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> low(n + 1), num(n + 1, 0);
    vector<bool> joint(n + 1, false);
    int timedfs = 0;

    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<void(int, int)> dfs = [&] (int u, int p) {
        low[u] = num[u] = ++timedfs;

        for(int v : adj[u]) {
            if(v == p)
                continue;
            if(!num[v]) {
                dfs(v, u);
                low[u] = min(low[v], low[u]);
                if(u == p) {
                    if(adj[u].size() > 1)
                        joint[u] = 1;
                }
                else
                    if(low[v] >= num[u])
                        joint[u] = 1;
            }
            else
                low[u] = min(low[u], low[v]);
        }
    };

    int cnt_dsu = 0;

    for(int i = 1; i <= n; i++)
        if(!num[i]) {
            dfs(i, i);
            cnt_dsu++;
        }

    for(int i = 1; i <= n; i++)
        if(joint[i])
            cout << adj[i].size() + cnt_dsu - 1 << '\n';
        else
            cout << cnt_dsu << '\n';
}
