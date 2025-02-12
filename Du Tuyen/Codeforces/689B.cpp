//Written by: ntannn_
//created in 18:19:14 - Thu 14/03/2024
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

ll n;
vll f[N], d(N, 1e9);

void solve() {
    queue<int> q;
    d[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto i : f[u]) {
            if(d[u] + 1 < d[i]) {
                d[i] = d[u] + 1;
                q.push(i);
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << d[i] << " " ;
}

void init() {
    cin >> n;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        f[i].eb(x);
    }
    for(int i = 1; i <= n; ++i) {
        if(i > 1) f[i].pb(i-1);
        if(i < n) f[i].pb(i+1);
    }
}

#define task "689B"
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