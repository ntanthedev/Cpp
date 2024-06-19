//Written by: ntannn_
//created in 13:09:55 - Tue 18/06/2024
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

ll n, a[N], lazy[N], tree[N], Q;

void build(int id, int l, int r) {
    if(l == r) 
        tree[id] = a[l];
    else {
        build(id * 2, l, (l + r) / 2);
        build(id * 2 + 1, (l + r) / 2 + 1, r);
        tree[id] = tree[id * 2] + tree[id * 2 + 1];
    }
}

void update(int id, int l, int r, int u, int v, ll w) {
    if(lazy[id] != 0) {
        tree[id] += (r - l + 1) * lazy[id];
        if(l != r)
            lazy[id * 2] += lazy[id],
            lazy[id * 2 + 1] += lazy[id];
        lazy[id] = 0;
    }   
    if(l > v || r < u)
        return;
    if(u <= l && r <= v) {
        tree[id] += (r - l + 1) * w;
        if(l != r)
            lazy[id * 2] += w,
            lazy[id * 2 + 1] += w;
        return; 
    }
    update(id * 2, l, (l + r) / 2, u, v, w);
    update(id * 2 + 1, (l + r) / 2 + 1, r, u, v, w);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

ll query(int id, int l, int r, int k) {
    if(lazy[id] != 0) {
        tree[id] += (r - l + 1) * lazy[id];
        if(l != r) 
            lazy[id * 2] += lazy[id],
            lazy[id * 2 + 1] += lazy[id];
        lazy[id] = 0;
    }

    if(l > k || r < k)
        return 0;

    if(l == r)
        return tree[id];
    
    int mid = (l + r) / 2;
    if(mid >= k) 
        return query(id * 2, l, mid, k);
    else 
        return query(id * 2 + 1, mid + 1, r, k);
}

void solve() {
    build(1, 1, n);
    while(Q--) {
        int c;
        cin >> c;
        if(c == 1) {
            ll x, y, u;
            cin >> x >> y >> u;
            update(1, 1, n, x, y, u);
        }
        else {
            int k;
            cin >> k;
            cout << query(1, 1, n, k) << '\n'; 
        }
    }
}

void init() {
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
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