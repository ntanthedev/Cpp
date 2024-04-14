//Written by: ntannn_
//created in 08:26:46 - Sun 14/04/2024
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

const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;

int n, m, k;
vector<ii> f[N];
vi s, vt;

void sub1() {
    s.resize(n + 2, INT_MAX);
    priority_queue<ii, vector<ii> , greater<ii>> q;
    vector<bool> P(n + 2, false);
    int be = vt[0];
    s[be] = 0;
    
    q.push({be, 0});

    while(!q.empty()) {
        ii u = q.top(); q.pop();

        if(P[u.fi])
            continue;

        P[u.fi] = 1;

        for(int i = 0; i < f[u.fi].size(); i++) {
            int v = f[u.fi][i].fi, w = f[u.fi][i].se;
            
        }
    }
}

void solve() {
    if(k == 2)
        sub1();
}

void init() {
    cin >> n >> m >> k;
    for(int i = 0, x; i < k; i++) {
        cin >> x;
        vt.pb(x);
    }
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        f[u].eb(v, w);
        f[v].eb(u, w);
    }
}

#define task "CITIES"
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