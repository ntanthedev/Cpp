//problem "CSES2143"
//created in 15:49:34 - Sun 28/07/2024

#include<bits/stdc++.h>

#define int int64_t
const int N = 5 * 1e4 + 5;

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m, q;
    cin >> n >> m >> q;

    bitset<10> f[n + 2];
    vector<vector<int>> adj(n + 2, vector<int>());
    vector<bool> visit(n + 1, false);

    for(int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    function<void(int)> dfs = [&](int u) {
        f[u].set(u);
        visit[u] = 1;
        vector<int> q;
        for(auto v : adj[u]) {
            if(!visit[v])
                dfs(v);
            f[u] |= f[v];
            if(find(adj[v].begin(), adj[v].end(), u) != adj[v].end())
                q.push_back(v);
        }
        for(auto v : q) 
            f[v] |= f[u];
    };

    for(int i = 1; i <= n; i++) {
        if(!visit[i])
            dfs(i);
        else {
            for(auto v : adj[i]) {
                if(find(adj[v].begin(), adj[v].end(), i) == adj[v].end())
                    f[i] |= f[v];
            }
        }
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        if(f[a].test(b))
            cout << "YES";
        else 
            cout << "NO";
        cout << '\n';
    }

    for(int i = 1; i <= 9; i++) 
        cout << i << (i < 10 ? "  " : " ") << f[i] << '\n';
}