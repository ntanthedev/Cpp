//Written by: ntannn_
//created in 15:43:04 - Sun 16/06/2024
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
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
 
const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;
 
ll n, m = 0, a[N], tour[N], st[N], ed[N], f[N], Q, tree[4 * N];
vector<int> adj[N];
 
void dfs(int u, int par) {
    st[u] = ++m;
    // tour[m] = u;
 
    for(auto v : adj[u]) {
        if(v != par)
            dfs(v, u);
    }
 
    ed[u] = ++m;
    // tour[m] = u;
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
    dfs(1, 0);
    memset(f, 0, sizeof(f));
 
    for(int i = 1; i <= n; i++) 
        f[st[i]] += a[i],
        f[ed[i]] += -a[i];
 
    build(1, 1, m);
 
    // for(int i = 1; i <= m; i++) 
    //     cout << tour[i] << " "; cout << '\n';
    
    // for(int i = 1; i <= m; i++) 
    //     cout << f[i] << " "; cout << '\n';
 
    while(Q--) {
        int c, s, x;
        cin >> c;
        if(c == 1) {
            cin >> s >> x;
            ll t = (-f[st[s]] + x);
            update(1, 1, m, st[s], t);
            update(1, 1, m, ed[s], -t);
 
            f[st[s]] += t;
            f[ed[s]] -= t;
            
            // cout << "up: ";
            // for(int i = 1; i <= m; i++)
            //     cout << f[i] << " "; cout << '\n';
        }
        else {
            cin >> s;
            // ll ans = 0;
            // for(int i = st[1]; i <= st[s]; i++) 
            //     ans += f[i];
            cout << query(1, 1, m, st[1], st[s]) << '\n';
        }
    }
 
}
 
void init() {
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    for(int x, y, i = 1; i < n; i++) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
}
 
#define task "CSES1138"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}

