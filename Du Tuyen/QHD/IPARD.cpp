//Written by: ntannn_
//created in 06:51:19 - Sun 17/03/2024
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

const int N = 5e3 + 10;
const ll MOD = 123456789;

int n;
ll f[N];

void solve() {
    f[0] = 1;
    for(int i =1; i <= n; i++) {
        for(int j = n; j >= i; --j) {
            if(f[j-i] != 0)
                f[j] = (f[j] + f[j - i]) % MOD;
        }
    }
    cout << f[n];
}

void init() {
    cin >> n;
}

#define task "IPARD"
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