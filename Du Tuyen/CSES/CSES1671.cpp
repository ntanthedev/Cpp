//problem "1671"
//created in 12:56:26 - Mon 06/05/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;


void dijkstra(int S, vector<vector<pair<int, int>>> f, vector<int> &D) {
    vector<bool> P(f.size(), 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    D[S] = 0;
    q.push({D[S], S});

    while(!q.empty()) {
        auto u = q.top(); q.pop();
        if(P[u.second])
            continue;
        P[u.second] = 1;

        for(auto i : f[u.second]) {
            auto[v, w] = i;
            if(D[u.second] + w < D[v])
                D[v] = D[u.second] + w;
            q.push({D[v], v});
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> f(n + 1, vector<pair<int, int>>()); 
    vector<int> D(n + 1, INT_MAX);

    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        f[u].push_back({v, w});
        f[v].push_back({u, w});
    }

    dijkstra(1, f, D);

    for(int i = 1; i <= n; i++) 
        cout << D[i] << " " ;
}