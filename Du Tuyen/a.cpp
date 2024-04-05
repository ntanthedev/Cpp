//template for problem 858D in codeforces by ntannn_
//created in 15:15:30 - Fri 05/04/2024
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
typedef pair<ll, ll> pll;

const int N = 3e5 + 10;
const ll MOD = 1e9 + 7;

ll n, base = 311, POW[15];
vector<vector<ll> > H;
map<ll, ll> m;

void solve() {
    
}

void init() {
    cin >> n;
    POW[0] = 1;
    for(int i = 1; i <= n; i++) {
        POW[i] = (POW[i-1] * base) % MOD;
    }
    H.resize(n + 2, vector<ll>(11));
    string tmp;
    for(int i = 1; i <= n; i++) {
        cin >> tmp; tmp = ' ' + tmp;
        H[i][0] = 0;
        for(int j = 1; j <= 9; j++) {
            H[i][j] = (H[i][j-1] * base + tmp[i] - 'a' + 1) % MOD;
        }
    }
}

signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case;
    for(cin >> test_case;test_case--;cout << '\n') {
        init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}