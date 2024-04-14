//Written by: ntannn_
//created in 20:45:16 - Sun 14/04/2024
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
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

int n, k;
int a[N][N];
ll f[N][N], ans = 0;

void solve() {
    for(int i = 1; i <= n; i++) 
        f[i][0] = 0, f[0][i] = 0;

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];

    for(int i = k; i <= n; i++) 
        for(int j = k; j <= n; j++) {
            ans = max(ans, f[i][j] - f[i-k][j] - f[i][j-k] + f[i-k][j-k]);
        }

    cout << ans;
}

void init() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            cin >> a[i][j];   
}

#define task "BONUS1"
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