//template for some simple code by ntannn_
//created in 19:58:27 - Mon 22/01/2024
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

bool dp[N][N];
string s;
ll n, ans = 1;

void solve() {
    memset(dp, false, sizeof dp);
    for(int i = 1; i <= n; i++) 
        dp[i][i] = true;
    for(int i = 1; i < n; i++) 
        dp[i+1][i] = true;
    for(ll k = 1; k < n; k++) 
        for(ll i = 1; i <= n-k+1; i++) {
            ll j = i + k;
            if(s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                ans = max(ans, abs(j - i + 1));
            }
        }
    cout << ans;
}

void init() {
    cin >> s;
    n = s.size();
    s = ' ' + s;
}

#define task "PALIND0"
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