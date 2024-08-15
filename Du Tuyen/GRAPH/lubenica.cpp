//problem "lubenica"
//created in 02:21:12 - Fri 16/08/2024

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 5;

int n, Q;
int par[N][18], maxc[N][18], minc[N][18], h[N];
vector<pair<int, int>> adj[N];

void dfs(int u, int p) {
    par[u][0] = p;
    
    for(auto [v, w] : adj[u]) {
        if(v == p) continue;

        h[v] = h[u] + 1;
        maxc[v][0] = w;
        minc[v][0] = w;

        dfs(v, u);
    }
}

void solve(int u, int v) {
    pair<int, int> ans = {INT_MIN, INT_MAX};

    if(h[u] != h[v]) {
        if(h[u] < h[v]) swap(u, v);
        int k = h[u] - h[v];

        for(int i = 17; i >= 0; --i) 
            if(k >> i & 1) {
                ans.first = max(ans.first, maxc[u][i]);
                ans.second = min(ans.second, minc[u][i]);
                u = par[u][i];
            }
    }

    if(u == v) 
        return cout << ans.second << " " << ans.first << '\n', void();

    for(int i = 17; i >= 0; i--) {
        if(par[u][i] != par[v][i]) {
            ans.first = max({ans.first, maxc[u][i], maxc[v][i]});
            ans.second = min({ans.second, minc[u][i], minc[v][i]});
            u = par[u][i];
            v = par[v][i];
        }
    }

    ans = {max({ans.first, maxc[u][0], maxc[v][0]}), min({ans.second, minc[u][0], minc[v][0]})};

    cout << ans.second << " " << ans.first << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for(int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    h[1] = 0;
    dfs(1, 1);
    for(int i = 1; i <= 17; i++) 
        for(int u = 1; u <= n; u++) {
            par[u][i] = par[par[u][i - 1]][i - 1];
            maxc[u][i] = max(maxc[u][i - 1], maxc[maxc[u][i - 1]][i - 1]);
            minc[u][i] = min(minc[u][i - 1], minc[minc[u][i - 1]][i - 1]);
    }

    cin >> Q;

    while(Q--) {
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }
}   