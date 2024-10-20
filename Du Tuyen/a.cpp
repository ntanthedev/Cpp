//problem "a"
//created in 09:00:38 - Sun 20/10/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, q;

    cin >> n >> q;

    vector<set<int>> adj(n + 1);

    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    while(q--) {
        int x, z, y;

        cin >> x >> y >> z;

        if(adj[x].count(y) && adj[y].count(z))
            cout << "YES";
        else 
            cout << "NO";
        cout << '\n';
    }
}