//problem "BFS_1"
//created in 02:35:36 - Tue 03/12/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "BFS_1"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, m;

    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    queue<int> q;

    q.push(1);
    vector<int> path;
    vector<int> trace(n + 1, 0);
    vector<bool> visited(n + 1, false);
    visited[1] = true;

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
    
    if(!visited[n]) {
        cout << "IMPOSSIBLE";
    } else {
        int u = n;
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