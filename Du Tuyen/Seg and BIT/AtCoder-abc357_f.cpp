//Written by: ntannn_
//created in 13:18:57 - Wed 17/07/2024
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

const int N = 2e5 + 10;
const ll MOD = 998244353;

ll a[N], b[N], n, Q, tree[4 * N], lza[4 * N], lzb[4 * N], sa[N], sb[N]; 

void build(int id, int l, int r) {
    if(l == r) {
        tree[id] = (a[l] * b[l]) % MOD;
        lza[id] = 0LL;
        lzb[id] = 0LL;
    }
    else {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tree[id] = (tree[id * 2] + tree[id * 2 + 1]) % MOD;
    }
}

inline void down(ll id, ll l, ll r, ll (&arr)[N], ll (&lz)[4 * N], ll(&s)[N]) {
    if(l != r) {
        lz[id * 2] += lz[id];
        lz[id * 2 + 1] += lz[id];
    }
    tree[id] += (((s[r] - s[l - 1]) % MOD) * (lz[id] % MOD)) % MOD;
    lz[id] = 0LL;
}

void update(int id, int l, int r, int u, int v, ll w, ll (&arr)[N], ll (&lz)[4 * N], ll(&s)[N]) {
    down(id, l, r, arr, lz, s);
    if(l > v || r < u)
        return;
    if(u <= l && r <= v) {
        tree[id] += (((s[r] - s[l - 1]) % MOD) * (w % MOD)) % MOD;
        if(l != r) {
            lz[id * 2] += w % MOD;
            lz[id * 2 + 1] += w % MOD;
        }
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, w, arr, lz, s);
    update(id * 2, mid + 1, r, u, v, w, arr, lz, s);
    tree[id] = (tree[id * 2] + tree[id * 2 + 1]) % MOD;
}

ll get(int id, int l, int r, int u, int v) {    
    if(lza[id != 0])
        down(id, l, r, a, lza, sa);
    if(lzb[id != 0])
        down(id, l, r, b, lzb, sb);
    
    if(l > v || r < u)
        return 0LL;
    
    if(u <= l && r <= v)
        return tree[id];
    
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void solve() {
    cin >> n >> Q;
    sa[0] = sb[0] = 0;
    for(int i = 1; i <= n; i++) 
        cin >> a[i], sa[i] = sa[i - 1] + a[i];
    for(int i = 1; i <= n; i++) 
        cin >> b[i], sb[i] = sb[i - 1] + b[i];
    
    build(1, 1, n);

    while(Q--) {
        ll c, l, r, w;
        cin >> c >> l >> r;
        if(c == 1) {
            cin >> w;
            update(1, 1, n, l, r, w, b, lzb, sb);
        }
        else if(c == 2) {
            cin >> w;
            update(1, 1, n, l, r, w, a, lza, sa);
        }
        else {
            cout << get(1, 1, n, l, r) << '\n';
        }
    }
}

#define task "AtCoder-abc357_f"
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
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}