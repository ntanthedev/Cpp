//Written by: ntannn_
//created in 16:03:47 - Fri 28/06/2024
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
const ll MOD = 1e9 + 7;

int n, a[N], Q, tree[4 * N], ans[N];
ii query[N];
map<int, int> last;
vector<ii> s[N];

void update(int id, int l, int r, int v, int w) {
    if(v > r || v < l)
        return;
    if(l == r) 
        return tree[id] += w, void();
    int mid = (l + r) / 2;
    update(id * 2, l, mid, v, w);
    update(id * 2 + 1, mid + 1, r, v, w);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    if(v < l || r < u)
        return 0;
    if(u <= l && r <= v)
        return tree[id];
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void solve() {
    for(int i = 1; i <= n; i++) {
        if(last.count(a[i])) 
            update(1, 1, n, last[a[i]], -1);
        
        last[a[i]] = i;
        update(1, 1, n, i, 1);

        for(auto j : s[i]) 
            ans[j.se] = get(1, 1, n, j.fi, i);
        
    }

    for(int i = 1; i <= Q; i++) 
        cout << ans[i] << "\n";
}

void init() {
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) { 
        cin >> a[i];
    }
    for(int i = 1, x, y; i <= Q; i++) {
        cin >> x >> y;
        s[y].eb(x, i);
    }
}

#define task "CSES1734"
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