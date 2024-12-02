//problem "BFS3"
//created in 02:47:34 - Tue 03/12/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

typedef pair<int, int> ii;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "BFS3"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, m, s, t;

    cin >> n >> m >> s >> t;

    vector<vector<ii>> adj(n + 1);
    vector<ii> trace(n + 1, {0, 0});
    vector<bool> vis(n + 1, false);

    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back({v, i});
    }

    for(int i = 1; i <= n; i++) 
        sort(adj[i].begin(), adj[i].end());

    queue<int> q;

    q.push(s);
    vis[s] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto [v, id] : adj[u]) {
            if(!vis[v]) {
                vis[v] = true;
                q.push(v);
                trace[v] = {u, id};
            }
        }
    }

    if(!vis[t]) {
        cout << "IMPOSSIBLE";
    } else {
        vector<int> path;
        int u = t;
        while(u != 0) {
            // cerr << u << ' ';
            path.push_back(trace[u].second);
            u = trace[u].first;
        }

        path.pop_back();
        reverse(path.begin(), path.end());

        // cout << path.size() << '\n';
        for(int u : path) cout << u << ' ';
    }
}