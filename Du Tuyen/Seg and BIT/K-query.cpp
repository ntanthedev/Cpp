//Written by: ntannn_
//created in 14:27:00 - Tue 23/04/2024
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

const int N = 3e4 + 10;
const ll MOD = 1e9 + 7;

int n, a[N], Q;
vvi tree;

void build(int id, int l, int r) {
    if(l == r) 
        tree[id].pb(a[l]);
    else {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        merge(all(tree[id * 2]), all(tree[id * 2 + 1]), back_inserter(tree[id]));
        sort(all(tree[id]));
    }
}

int query(int id, int l, int r, int d, int c, int k) {
    if(l > c || r < d)
        return 0;
    if(d <= l && r <= c) 
        return tree[id].size() - (upper_bound(all(tree[id]), k) - tree[id].begin());
    
    int mid = (l + r) / 2;

    return query(id * 2, l, mid, d, c, k) + query(id * 2 + 1, mid + 1, r, d, c, k);
}

void solve() {
    tree.resize(5 * n, vi());
    build(1, 1, n);

    cin >> Q;
    while(Q--) {
        ll l, r, k;
        cin >> l >> r >> k;
        cout << query(1, 1, n, l, r, k) << '\n';
    }
}

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

#define task "K-query"
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