//problem "atcoder_dp_g"
//created in 13:27:46 - Fri 12/04/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int n, m;
vector<vector<int>> f;
vector<int> d;

void dfs(int u) {
    if(d[u]) return;
    for(auto v : f[u]) {
        if(!d[v]) dfs(v);
        d[u] = max(d[v] + 1, d[u]);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    f.resize(n + 1);
    d.resize(n + 1, 0);
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        f[u].push_back(v);
    }

    for(int u = 1; u <= n; u++) {
        dfs(u);
    }

    cout << *max_element(d.begin(), d.end()) ;
}