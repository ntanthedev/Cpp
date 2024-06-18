//Written by: ntannn_
//created in 22:56:11 - Sun 16/06/2024
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 2e5 + 10;
const int NMax = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll n, f[NMax], h[N], st[N], ed[N], m = 0, up[N][22], tree[NMax], Q;
vector<pll> adj[N];
pll E[N];

void dfs(int u, ll w) {
    st[u] = ++m;
    f[m] = /* f[st[up[u][0]]] + */ w;

    for(auto [v, w] : adj[u]) {
        if(v != up[u][0]) {
            up[v][0] = u;
            h[v] = h[u] + 1;
            for(int i = 1; i <= 19; i++)
                up[v][i] = up[up[v][i - 1]][i - 1];
            dfs(v, w);
        }
    }

    ed[u] = ++m;
    f[m] = -f[st[u]];
}

int lca(int u, int v) {
    if(h[u] != h[v]) {
        if(h[u] < h[v])
            swap(u, v);
        
        int k = h[u] - h[v];
        for(int j = 0; (1 << j) <= k; j++) 
            if(k >> j & 1)
                u = up[u][j];
    }

    if(u == v) 
        return u;

    for(int j = __lg(h[u]); j >= 0; j--) 
        if(up[u][j] != up[v][j])
            u = up[u][j], v = up[v][j];

    return up[u][0];
}

void build(int id, int l, int r) {
    if(l == r) 
        tree[id] = f[l];
    else {
        build(id * 2, l, (l + r) / 2);
        build(id * 2 + 1, (l + r) / 2 + 1, r);
        tree[id] = tree[id * 2] + tree[id * 2 + 1];
    }
}
 
void update(int id, int l, int r, int u, ll w) {
    if(l == r) {
        tree[id] += w;
    }
    else {
        int mid = (l + r) / 2;
        if(mid >= u)
            update(id * 2, l, mid, u, w);
        else 
            update(id * 2 + 1, mid + 1, r, u, w);
        tree[id] = tree[id * 2] + tree[id * 2 + 1];
    }
}
 
ll query(int id, int l, int r, ll u, ll v) {
    if(r < u || l > v) 
        return 0LL;
    if(u <= l && r <= v)
        return tree[id];
    int mid = (l + r) / 2;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}
 
void solve() {
    up[1][0] = 0;
    h[1] = 1;
    dfs(1, 0);    

    // for(int i = 1; i <= m; i++) 
    //     cout << f[i] << " "; cout << '\n';
    // cout << lca(6, 7) << '\n';
    // exit(0);

    build(1, 1, m);

    cin >> Q;

    while(Q--) {
        ll c, a, b;
        
        cin >> c >> a >> b; 

        if(c == 1) {
            int g = (h[E[a].fi] > h[E[a].se] ? E[a].fi : E[a].se);
            ll t = b - f[st[g]];
            // cout << f[st[g]] << " ";
            update(1, 1, m, st[g], t);
            update(1, 1, m, ed[g], -t);
            f[st[g]] += t;
            // cout << f[st[g]] << '\n';
            f[ed[g]] -= t;
        }
        else {
            if(a == b) {
                cout << 0 << '\n';
                continue;
            }
                
            ll s = lca(a, b);
            // cout << "lca(" << a << ", " << b << "): " << s << '\n';
            cout << query(1, 1, m, st[s] + 1, st[a]) + query(1, 1, m, st[s] + 1, st[b]) << '\n';
            // cout << f[st[a]] + f[st[b]] - 2*f[st[s]] << '\n';
        }
    }
}   

void init() {
    cin >> n;
    for(int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
        E[i] = {u, v};
    }
}

#define task "a"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        // freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}
