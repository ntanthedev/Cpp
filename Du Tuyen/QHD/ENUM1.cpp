//template for some simple code by ntannn_
//created in 21:24:58 - Mon 22/01/2024
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

const int N = 1e3 + 10;
const ll MOD = 1e9 + 7;

ll n, f[N][N], ans = 0;

ll solve(int i, int d) {
    if(i > n) {
        if(d == 0)
            return 1;
        return 0;
    }
    if(f[i][d] != -1)
        return f[i][d];
    f[i][d] = 0;
    if(d + 1 <= n - i) 
        f[i][d] += solve(i + 1, d + 1);
    if(d > 0)
        f[i][d] += solve(i + 1, d - 1);
    return f[i][d] % MOD;
}

void init() {
    cin >> n;
    if(n%2 != 0) 
        return cout << 0, void();
    memset(f, -1, sizeof f);
    cout << solve(1, 0) % MOD;
}

#define task "ENUM1"
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
        // solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}