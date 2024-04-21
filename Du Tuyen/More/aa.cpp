//Written by: ntannn_
//created in 18:21:55 - Sat 20/04/2024
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

ll n, m, tree[N], lz[N];

void update(int id = 1, int l = 1, int r = n, int u, int v) {
    if(lz[id]) {
        tree[id] += (r - l + 1) * lz[id];
        lz[id * 2] += lz[id];
        lz[id * 2 + 1] += lz[id]; 
    }

    if(r < u || l > v)
        return;
    
    if(u <= l && r <= v) {
        lz[id * 2]++;
        lz[id * 2 + 1]++;
        return; 
    }

    int mid = (l + r) / 2;

    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);

    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

void solve() {
          
}

void init() {
    cin >> n >> m;

    while(m--) {
        int u, v;
        cin >> u >> v;
        update(u, v);
    }
}

#define task "aa"
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