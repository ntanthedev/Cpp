//problem "a"
//created in 23:36:01 - Sat 31/08/2024

#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
typedef pair<int, long long> ii;
typedef long long ll;

int n, q, m = 0;
int in[N], out[N], par[N][18], h[N];
ll f[N], tree[4 * N];
vector<ii> adj[N];
tuple<int, int, int> edge[N];

void dfs(int u, int p, int val) {
    in[u] = ++m;
    f[m] = val;

    for(auto [v, w] : adj[u]) {
        if(v == p) continue;
        
        par[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v, u, w);
    }

    out[u] = ++m;
    f[m] = -val;
}

int lca(int u, int v) {
    if(h[u] != h[v]) {
        if(h[u] < h[v]) swap(u, v);

        int k = h[u] - h[v];

        for(int i = __lg(k); i >= 0; i--) 
            if(k >> i & 1)
                u = par[u][i];
    }

    if(u == v) 
        return u;

    for(int i = __lg(h[u]); i >= 0; i--) 
        if(par[u][i] != par[v][i]) 
            u = par[u][i], v = par[v][i];
    
    return par[u][0];
}

void update(int id, int l, int r, int u, int w) {
    if(l > u || r < u) 
        return;
    if(l == r) 
        return tree[id] = w, void();
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, w);
    update(id * 2 + 1, mid + 1, r, u, w);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

ll get(int id, int l, int r, int u, int v) {
    if(l > v || r < u) 
        return 0LL;
    if(u <= l && r <= v) 
        return tree[id];
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edge[i] = {u, v, w};
    }

    dfs(1, 0, 0);

    for(int i = 1; i <= 17; i++) 
        for(int u = 1; u <= n; u++) 
            par[u][i] = par[par[u][i - 1]][i - 1];
        
    for(int i = 1; i <= m; i++) 
        update(1, 1, m, i, f[i]);

    cin >> q;
    while(q--) {
        int c, a, b;
        cin >> c >> a >> b;
        if(c & 1) {
            auto &[u, v, w] = edge[a - 1];
            if(in[u] > in[v])
                swap(u, v);
            update(1, 1, m, in[v], b);
            update(1, 1, m, out[v], -b);
            f[in[v]] = b;
            f[out[v]] = -b;
            w = b;
        }
        else {
            int p = lca(a, b); printf("check lca: %d \n", p);
            cout << get(1, 1, m, in[p], in[a]) + get(1, 1, m, in[p], in[b]) - f[p] << '\n';
        }
    }
}