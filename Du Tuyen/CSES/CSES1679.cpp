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
    vector<int> b(n + 1, false);
    vector<int> ans;
    queue<int> f;

    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        b[v]++;
    }

    for(int i = 1; i <= n; i++) {
        if(!b[i]) 
            f.push(i);
    }

    while(!f.empty()) {
        int u = f.front(); f.pop();
        ans.push_back(u);
        for(auto v : adj[u]) {
            b[v]--;
            if(!b[v]) {
                f.push(v);
            }
        }
    }

    if(ans.size() < n) 
        cout << "IMPOSSIBLE";
    else 
        for(auto i : ans) 
            cout << i << " ";
}