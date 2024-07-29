//Written by: ntannn_
//created in 09:27:13 - Mon 29/07/2024
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

const int N = 5e4 + 10;
const ll MOD = 1e9 + 7;

int n, m;
vi adj[N], ans;
int d[N];
bool p[N];

void dfs(int u, int h) {
    if(h == 0) 
        return;
    p[u] = 0;
    for(int v : adj[u]) {
        dfs(v, max(h - 1, d[v]));
    }
}

void solve() {
    cin >> n >> m;

    for(int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    for(int i = 1; i <= n; ++i) {
        cin >> d[i];
        p[i] = (d[i] < 1);
    }

    for(int i = 1; i <= n; ++i) {
        if(d[i] > 0) 
            dfs(i, d[i]); 
    }

    for(int i = 1; i <= n; ++i) 
        if(p[i])
            ans.eb(i);
    
    cout << ans.size() << '\n';

    for(auto i : ans)
        cout << i << " " ;
}

#define task "PUTOVAN"
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