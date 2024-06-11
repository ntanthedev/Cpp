//Written by: ntannn_
//created in 21:37:15 - Sat 08/06/2024
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
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 2e6 + 10;
const ll MOD = 1e9 + 7;

ll m, Q, n = 0, s = 0;
ll a[N], b[N], leaf[N];
map<ll, ll> M;
pll tree[N];

void build(ll id, ll l, ll r) {
    tree[id].se = 0;
    if(l == r) {    
        tree[id].fi = a[l];
        s += M[a[l]];
        tree[id].se = s;
        leaf[l] = id;
        // index[id] = l;
    }
    else {
        ll mid = (l + r) / 2;
        build(id * 2, l, mid); 
        build(id * 2 + 1, mid + 1, r);
        tree[id].fi = min(tree[id * 2].fi, tree[id * 2 + 1].fi);
    }
}

void update(int id, int l, int r, int u, int v, int k) {
    if(tree[id].se != 0) {
        // tree[id].fi += k;
        if(l != r)
            tree[id * 2].se += tree[id].se,
            tree[id * 2 + 1].se += tree[id].se, 
            tree[id].se = 0; 
    }
    if(v < l || r < u)
        return;
    if(u <= l && r <= v)
        return 
        tree[id].se += k, 
        void();
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, k);
    update(id * 2 + 1, mid + 1, r, u, v, k);
}

ll query(ll id, ll l, ll r, ll k) { 
    if(tree[id].se != 0) 
        if(l != r) {
            tree[id * 2].se += tree[id].se;
            tree[id * 2 + 1].se += tree[id].se;
            tree[id].se = 0;
        }
    
    if(tree[id].fi > k) 
        return -1;
    if(l == r) {
        return l;
    }
    ll mid = (l + r) / 2;
    if(tree[id * 2 + 1].fi <= k)
        return query(id * 2 + 1, mid + 1, r, k);
    return query(id * 2, l, mid, k);
}
void solve() {
    build(1, 1, n);
    // for(int i = 1; i <= n; i++) 
    //     cout << tree[leaf[i]].fi << " " << tree[leaf[i]]se << '\n';
    // return ;
    while(Q--) {
        ll x;
        cin >> x;
        ll ans = query(1, 1, n, x);
        cout << tree[leaf[ans]].se + 1 << '\n';
        update(1, 1, n, ans, n, 1);
    }
}

void init() {
    cin >> m >> Q;
    for(int i = 1; i <= m; i++) 
        cin >> b[i], M[b[i]]++;
    for(auto i : M)
        a[++n] = i.fi;
}

#define task "a"
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