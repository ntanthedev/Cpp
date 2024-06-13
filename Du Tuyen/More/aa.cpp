//Written by: ntannn_
//created in 10:56:10 - Wed 12/06/2024
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

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll a, b;
ll f[20][2];

ll cal_c(int i, bool ok) {
    if(i < 0)
        return 0;
    if(f[i][ok] != -1)
        return f[i][ok];
    
}

ll cal(int x) {
    vector<int> s;
    while(x > 0) {
        s.pb(x / 10);
        x /= 10;
    }
    memset(f, -1, sizeof(f));
    return cal_c(s.size() - 1, 0);
} 

void solve() {
    cout << cal(b) - cal(a - 1) << '\n';
}

void init() {
    cin >> a >> b;    
}

#define task "aa"
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
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}