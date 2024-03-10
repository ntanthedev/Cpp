//Written by: ntannn_
//created in 16:15:08 - Sat 09/03/2024
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

ll n, m;
pll a[N];
ll dp[N][N];
vector<vvi> f(N, vvi(N));

void solve() {
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i].fi <= j) {
                dp[i][j] = max(dp[i-1][j-a[i].fi] + a[i].se, dp[i-1][j]);
                if(dp[i-1][j-a[i].fi] + a[i].se > dp[i-1][j]) {
                }
                else 
                    f[i][j] = f[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
                f[i][j] = f[i-1][j];
            }
        }
    }   
    cout << dp[n][m] << '\n';
    for(auto i : f[n][m])
        cout << i << " ";
}

void init() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> a[i].fi >> a[i].se;
}

#define task "CAITUI"
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