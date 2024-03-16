//template for codeforces by ntannn_
//created in 22:20:52 - Sat 16/03/2024
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

ll n, a[N];

void solve() {
    map<int, int> m;
    ll ans = 0, gmax = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i], m[a[i]]++, gmax = max(gmax, a[i]);
    for(int i = 0; i <= n; i++) {
        if(m[i] < i + 1)
            return cout << i, void();
    }
    cout << gmax + 1;
}

signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case;
    for(cin >> test_case;test_case--;cout << '\n') {
        // init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}