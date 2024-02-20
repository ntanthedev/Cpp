//template for some simple code by ntannn_
//created in 20:57:21 - Thu 15/02/2024
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

ll n, a[N];

void solve() {
    map<ll, ll> M;
    vector<ll> dp(N, 0);
    ll gmax1 = 0, gmax2 = 0;
    cin >> n;
    n >>= 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];    
        if(M[a[i] - 1] != 0) {
            dp[i] = max(dp[M[a[i] - 1]], dp[i]) + 1;
        }
        M[a[i]] = i;
        gmax1 = max(gmax1, dp[i]);
    }
    M.clear();
    for(int i = n + 1; i <= n * 2; i++) {
        cin >> a[i];
        if(M[a[i] + 1] != 0) {
            dp[i] = max(dp[M[a[i] + 1]], dp[i]) + 1;
        }
        M[a[i]] = i;
        gmax2 = max(gmax2, dp[i]);
    }
    if(gmax1 == 0 || gmax2 == 0)
        return cout << -1, void();
    cout << (n - gmax1 - 1) + (n - gmax2 - 1) << '\n'; 
}

#define task "LHSEQ"
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
        // init();
        solve();
        cout << '\n';
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}