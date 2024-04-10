//Written by: ntannn_
//created in 09:20:38 - Wed 10/04/2024
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

ll n, a[N][4], dp[N][4];

void solve() {
    for(int i = 1; i <= 3; i++)
        dp[1][i] = a[1][i];
    for(int i = 2; i <= n; i++) {
        dp[i][1] = max(dp[i-1][2], dp[i-1][3]) + a[i][1];
        dp[i][2] = max(dp[i-1][1], dp[i-1][3]) + a[i][2];
        dp[i][3] = max(dp[i-1][1], dp[i-1][2]) + a[i][3];
    }
    cout << max({dp[n][1], dp[n][2], dp[n][3]});
}

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i][1] >> a[i][2] >> a[i][3];
}

#define task "atcoder_dp_c"
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