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

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll n, m, a[N], c;
pll lmax[N];

void build(int id, int l, int r) {
    if(l == r) {
        lmax[id].fi = a[l];
        lmax[id].se = l;
    }
    else {
        int mid = (l + r) / 2;
        build(id * 2, l, mid); 
        build(id * 2 + 1, mid + 1, r);
        lmax[id] = (lmax[id * 2].fi >= lmax[id * 2 + 1].fi) ? lmax[id * 2] : lmax[id * 2 + 1];
    }
}

ll query(int id, int l, int r, int k) {
    if(lmax[id].fi < k) {
        return 0;
    }
    if(l == r) {
        lmax[id].fi -= k;
        return lmax[id].se;
    }
    int mid = (l + r) / 2, vt;
    if(lmax[id * 2].fi >= k) {
        vt = query(id * 2, l, mid, k);
        lmax[id] = (lmax[id * 2].fi >= lmax[id * 2 + 1].fi) ? lmax[id * 2] : lmax[id * 2 + 1];
        return vt;
    }
    else {
        vt = query(id * 2 + 1, mid + 1, r, k);
        lmax[id] = (lmax[id * 2].fi >= lmax[id * 2 + 1].fi) ? lmax[id * 2] : lmax[id * 2 + 1];
        return vt;
    }
}

void solve() {
    build(1, 1, n);
    for(int i = 1; i <= m; i++) {
        cin >> c;
        cout << query(1, 1, n, c) << " ";
    }
}

void init() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

#define task "Hotel Queries"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    // cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}