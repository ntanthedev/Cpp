//problem "BFS2"
//created in 02:35:36 - Tue 03/12/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "BFS2"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, m, s, t;

    cin >> n >> m >> s >> t;

    vector<vector<int>> adj(n + 1);

    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 1; i <= n; i++) 
        sort(adj[i].begin(), adj[i].end());

    queue<int> q;

    q.push(s);
    vector<int> path;
    vector<int> trace(n + 1, 0);
    vector<bool> visited(n + 1, false);
    visited[s] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
                trace[v] = u;
            }
        }
    }
    
    if(!visited[t]) {
        cout << "IMPOSSIBLE";
    } else {
        int u = t;
        while(u != 0) {
            path.push_back(u);
            u = trace[u];
        }

        reverse(path.begin(), path.end());

        // cout << path.size() << '\n';
        for(int u : path) {
            cout << u << ' ';
        }
    }
}