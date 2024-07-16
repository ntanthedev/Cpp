//template for problem a in codeforces by ntannn_
//created in 15:59:49 - Sun 14/07/2024
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
typedef pair<ll, ll> pll;

const int N = 3e5 + 10;
const ll MOD = 1e9 + 7;


void solve() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> adj(n + 1, vector<ll>());
    vector<int> h(n + 1), deep(n + 1);
    map<int, vector<int>> m;
    for(int v = 2, u; v <= n; v++) {
        cin >> u;
        adj[u].eb(v);
    }

    // vector<int> ans;
    function<void(int)> dfs = [&](int u) {
        // ans.pb(h[u]);
        deep[u] = h[u];
        for(auto v : adj[u]) {
            h[v] = h[u] + 1;
            dfs(v);
            deep[u] = max(deep[u], deep[v]);
        }
        m[h[u]].pb(u);
    };
    h[1] = 0;
    dfs(1);
    auto max_deep = (--m.end())->fi;
    function<bool(int)> check = [&](int x) {
        int res = 0;
        for(auto i : m[x]) {
            res += (deep[i] - 1) / x;
        }
        return (res <= k);
    };

    cout << check(1) << '\n';
    exit(0);
    int ans;
    int l = 0, r = max_deep;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) 
            ans = mid,
            r = mid - 1;
        else 
            l = mid + 1;
    }

    cout << ans;
}

//for(int i = 1; i <= n; i++) cin >> a[i]; for(int j = 1; j <= n; j++) cin dsddlldldldlldfjfjfjfjfjjf

signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case;
    for(cin >> test_case;test_case--;cout << '\n') {
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}