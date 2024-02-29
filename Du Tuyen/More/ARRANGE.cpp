//Written by: ntannn_
//created in 21:08:39 - Wed 28/02/2024
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

ll n, m, k;

void solve() {
    ll l = 1, r = n, ans = INT_MAX;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if((mid * k) - ((1 + k) * k / 2) + (mid * (n - k + 1) - (k + n) * (n - k + 1) / 2) + n - mid <= m)
            l = mid + 1, ans = mid;
        else 
            r = mid - 1;
    }
    cout << ans << '\n';
}

void init() {
    cin >> n >> m >> k;
}

#define task "ARRANGE"
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