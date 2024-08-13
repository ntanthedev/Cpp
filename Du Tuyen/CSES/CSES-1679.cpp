//problem "CSES-1679"
//created in 15:05:46 - Tue 13/08/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;

    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>());
    vector<bool> b(n + 1);

    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    
}