//template for some simple code by ntannn_
//created in 10:21:01 - Sat 27/01/2024
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

ll n, m;
vll f[N];
vi trace(N, -1);
vi ans;
bool flag = 0;
vi res;

void dfs(int x) {
    if(flag) return;
    for(auto u : f[x]) {
        if(u == trace[x]) continue;
        if(flag) return;
        if(trace[u] != -1) {
            res.pb(u);
            for(int i = ans.size()-1; i >= 0; i--) {
                res.pb(ans[i]);
                if(ans[i] == u && i != ans.size()-1)
                    break;
            }
            cout << res.size() << '\n';
            for(auto i : res)
                cout << i << " " ;
            flag = 1;
            return;
        }
        trace[u] = x;
        ans.pb(u);   
        dfs(u);
    }
}

void solve() {
    // memset(trace, 0, sizeof(trace))
    for(int i = 1; i <= n; i++) {
        if(!f[i].empty() && trace[i] == -1)
            dfs(i);
        if(flag)
            break;
    }
    if(!flag)
        return cout << "IMPOSSIBLE", void();    
}

void init() {
    cin >> n >> m;
    for(int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        f[x].pb(y);
        f[y].pb(x);
    }
}

#define task "RoundTrip"
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