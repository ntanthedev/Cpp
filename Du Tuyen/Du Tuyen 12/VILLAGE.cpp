//problem "VILLAGE"
//created in 07:45:26 - Mon 12/08/2024

#include<bits/stdc++.h>

// #define int int64_t
const int N = 2e5 + 5;

using namespace std;


int n, q;
int par[N][19], h[N];
vector<int> adj[N];
pair<int, int> f[N];
bool sub3 = 1;

void dfs(int u, int p) {

    for(auto v : adj[u]) {
        if(v == p) continue;

        par[v][0] = u;
        h[v] = h[u] + 1;
        for(int i = 1; i < 19; i++) 
            par[v][i] = par[par[v][i - 1]][i - 1];
        
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if(h[u] != h[v]) {
        if(h[u] < h[v]) 
            swap(v, u);
        
        int k = h[u] - h[v];
        for(int j = 0; (1 << j) <= k; j++) 
            if(k >> j & 1)
                u = par[u][j];
    }

    if(u == v) 
        return u;
    
    for(int j = __lg(h[u]); j >= 0; j--) {
        if(par[u][j] != par[v][j]) 
            u = par[u][j],
            v = par[v][j];
    }

    return par[u][0];
}

void travel(int u, int v, int w) {
    if(u == v) 
        f[u] = {w, 1};

    int p = lca(u, v);

    while(u != p) {
        if(!f[u].first)
            f[u] = {w, 1};
        else 
            f[u].second += (f[u].first == w);
        u = par[u][0];
    }

    while(v != p) {
        if(!f[v].first)
            f[v] = {w, 1};
        else 
            f[v].second += (f[v].first == w);
        v = par[v][0];
    }

    if(!f[p].first)
        f[p] = {w, 1};
    else 
        f[p].second += (f[p].first == w);
}

bool query(int u, int v) {
    if(f[u].second != f[v].second) 
        return false;
    int w = f[u].second, p = lca(u, v);

    cerr << "query: " << u << " " << v << " " << p << " " << w << '\n';

    while(u != p) {
        u = par[u][0];
        if(f[u].second != w) 
            return false;
    }

    while(v != p) {
        v = par[v][0];
        if(f[v].second != w) 
            return false;
    }

    return true;
}

void sub2() {
    for(int i = 1; i <= n; i++) f[i] = {0, 0};

    h[1] = 1;
    par[0][0] = 0;
    dfs(1, 0);
    
    while(q--) {
        int c, u, v, t;
        cin >> c;
        if(c & 1) {
            cin >> u >> v >> t; 
                travel(u, v, t);
            }
        else {
            cin >> u >> v;
            cout << query(u, v) << '\n';
        }

        cerr << "\n--------------\n";
        for(int i = 1; i <= n; i++) 
            cerr << i << ": " << f[i].first << " " << f[i].second << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "VILLAGE"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> q;

    for(int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if((!(x ^ i) && !(y ^ (i + 1))) || (!(y ^ i) && !(x ^ (i + 1))))
            sub3 = 0;
    }

    if(n <= 5000 && q <= 5000) {
        sub2();
    }
}