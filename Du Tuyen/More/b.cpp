//problem "b"
//created in 10:44:09 - Tue 09/07/2024

#include<bits/stdc++.h>

#define int int64_t
#define fi first 
#define se second

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());

    for(int i = 1, u, v, k; i < n; i++) {
        cin >> u >> v >> k;
        adj[u].emplace_back(v, k);
        adj[v].emplace_back(u, k);
    }

    function<int(int)> bfs = [&](int x) {
        vector<int> d(n + 1, -1);
        queue<int> q;
        q.push(x);
        d[x] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto [v, k] : adj[u]) {
                if(d[v] != -1 || d[u] + k >= d[v]) 
                    continue;
                d[v] = d[u] + k;
                q.push(v);
            }
        }
        return *max_element(d.begin(), d.end());
    };

    for(int i = 1; i <= n; i++) {
        cout << bfs(i);
    }
}