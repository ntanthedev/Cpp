//problem "RMOVE"
//created in 08:37:58 - Mon 25/11/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "RMOVE"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, m;

    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> h(n + 1, 0);
    vector<int> res, path;

    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    if(n == 1) 
        return cout << 0 << '\n' << 1 << '\n' << 1, signed();

    h[1] = 1;
    path.push_back(1);

    function<void(int, int)> dfs = [&](int u, int p) {
        for(int v : adj[u]) {
            if(v == p || h[v]) 
                continue;
            path.push_back(v);
            h[v] = h[u] + 1;
            
            if(v == n && h[v] & 1 && (path.size() < res.size() || res.empty())) {
                res = path;
            }
            else {
                dfs(v, u);
            } 
            path.pop_back();    
        }    
    };

    dfs(1, 1);

    if(res.empty())
        return cout << -1, signed();

    int t = res.size() / 2;

    cout << t << '\n';

    for(int i = 0; i <= t; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    for(int i = res.size() - 1; i >= t; i--) {
        cout << res[i] << ' ';
    }
}