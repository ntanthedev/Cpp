// Written by: ntannn_
// created in 22:28:41 - Tue 25/06/2024
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

ll n, w[N], m[N], p[N];
vi adj[N];

void dfs(int u, int par) {
    for(int v: adj[u]) {
        if(v == par)
            continue;

        dfs(v, u);

        p[u] = max(p[u], p[v]);
        m[u] = max(m[u], m[v]);
    }

    ll s = w[u] + (p[u] - m[u]);
    if(s > 0)
        m[u] += s;
    else
        p[u] -= s;
}

void solve() {
    dfs(1, 0);

    cout << m[1] + p[1];
}

void init() {
    cin >> n;

    for(int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        adj[a].eb(b);
        adj[b].eb(a);
    }

    for(int i = 1; i <= n; i++)
        cin >> w[i];
}

#define task "274B"
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