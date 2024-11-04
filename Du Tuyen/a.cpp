//problem "a"
//created in 09:58:00 - Sat 02/11/2024

#include<bits/stdc++.h>

#define int long long

using namespace std;

typedef pair<int, int> ii;

void dijkstra(int s, vector<vector<ii>>& adj, vector<int>& dist) {
    int n = adj.size();
    dist.assign(n, INT_MAX);
    vector<bool> vis(n, false);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for(auto [v, w] : adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    
    int n, m;
    cin >> n >> m;
    vector<vector<ii>> adj(n + 1);

    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }

    vector<int> D;

    dijkstra(1, adj, D);

    for(int i = 1; i <= n; i++) {
        cout << D[i] << " ";
    }    
}