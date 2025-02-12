// Written by: ntannn_
// created in 09:37:00 - Mon 18/03/2024
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

const int N = 1e2 + 10;
const ll MOD = 1e9 + 7;

ll f[N][N][N], n, m, k;

ll solve(int a, int b, int c) {
    if(a == 0)
        return 1;
    if(b == 0 || a < 0 || c == 0)
        return 0;

    if(f[a][b][c] != -1)
        return f[a][b][c];

    for(int i = 0; i <= c; i++) {
        f[a][b][c] += f[a - i][b - 1][i];
    }
    return f[a][b][c];
}

void init() {
    cin >> n >> m >> k;

    memset(f, -1, sizeof f);

    cout << solve(n, m, k);
}

#define task "MARB"
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
        // solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}