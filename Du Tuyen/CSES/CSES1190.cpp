//Written by: ntannn_
//created in 13:11:25 - Thu 20/06/2024
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

ll n, a[N], Q;

struct pt {
    ll suf, pre, sum, ans;
};

pt tree[N];

pt make(ll val) {
    pt node;
    node.suf = node.pre = node.ans = max(0LL, val);
    node.sum = val;
    return node;
}

pt combine(pt l, pt r) {
    pt node;
    node.pre = max(l.pre, l.sum + r.pre);
    node.suf = max(r.suf, r.sum + l.suf);
    node.sum = l.sum + r.sum;
    node.ans = max({l.ans, r.ans, l.suf + r.pre});
    return node;
}

void build(int id, int l, int r) {
    if(l == r) 
        tree[id] = make(a[l]);
    else {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
    }
}

void update(int id, int l, int r, int u, ll w) {
    if(l == r) 
        tree[id] = make(w);
    else {
        int mid = (l + r) / 2;
        if(u <= mid) 
            update(id * 2, l, mid, u, w);
        else 
            update(id * 2 + 1, mid + 1, r, u, w);
        tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
    }
}

// pt query(int id, int l, int r, int u, int v) {

// }

void solve() {
    build(1, 1, n);
    ll k, x;
    while(Q--) {
        cin >> k >> x;
        update(1, 1, n, k, x);
        cout << tree[1].ans << '\n';
    }   
}

void init() {
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
}

#define task "CSES1190"
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