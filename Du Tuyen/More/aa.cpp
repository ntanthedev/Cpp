//problem "aa"
//created in 17:39:35 - Thu 19/09/2024

#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, Q;
vector<int> adj[N];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> Q;

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
}