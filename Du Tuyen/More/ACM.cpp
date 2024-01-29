//template for some simple code by ntannn_
//created in 21:21:25 - Fri 26/01/2024
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

ll n, a[N], b[N], ans = 0;
pll c[N];

void solve() {
    sort (c + 1, c + 1 + 2 * n, greater<pll>());
    for(int i = 1; i <= n; i++) {
        ans += b[c[i].se];
    }
    for(int i = 1; i <= n; i++) {
        ans += a[c[i + n].se];
    }
    cout << ans;
}

void init() {
    cin >> n;
    for(int i = 1; i <= 2*n; i++) {
        cin >> a[i] >> b[i];
        c[i].fi = a[i] - b[i];
        c[i].se = i;
    }
}

#define task "ACM"
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