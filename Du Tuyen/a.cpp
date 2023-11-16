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

const int N = 2e2 + 2;
const int NN = N * N;
const ll MOD = 1e9 + 7;

ll n, dp[2][2 * NN], p, a[N];

void solve() {
	dp[0][NN] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 2 * NN; j++) {
            if(dp[0][j] > 0) {
                dp[1][j] += dp[0][j];
                dp[1][j] %= MOD;
                dp[1][j + a[i]] += dp[0][j];
                dp[1][j + a[i]] %= MOD;
            }
        }
        for(int j = 1; j <= 2 * NN; j++) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }
    cout << (dp[0][NN] - 1 + MOD) % MOD;
}

void init() {
    cin >> n >> p;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= p;
    }
    
}

#define task "a"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}