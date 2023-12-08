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

ll m, n, t[N];
vll f[N];
vector<bool> vis, way;

bool check(long long mid) {
    queue<int> q;
    vis.assign(n + 1, 0);

    q.push(1);
    vis[1] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v: f[u]) {
            if(vis[v] || abs(t[u] - t[v]) > mid)
                continue;

            vis[v] = true;
            q.push(v);
        }
    }
    return vis[n];
}

void solve() {
    vis.resize(n + 1, 0);
    ll l = 0, r = 1e18, mid, ans;
    while(l <= r) {
        mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
            way = vis;
        } else
            l = mid + 1;
    }
    cout << ans << '\n';
    for(auto i : way)
        if(i)
            cout << i << " " ;
}

void init() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> t[i];
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        f[u].eb(v);
        f[v].eb(u);
    }
}

#define task "WILDLIFE"
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