//template for problem 1611F in codeforces by ntannn_
//created in 08:37:23 - Thu 04/04/2024
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

ll n, a[N], s;

void solve() {
    pll ans = {0, 0};
    a[0] = 0;
    ll l = 1, r = 1, res = a[1];
    if(a[1] >= -s) ans = {1, 1};
    while(r <= n) {
        while((res < -s || a[l] < -s) && l < r) 
            res -= a[l++];
        if(res >= -s && r - l >= ans.se - ans.fi)
            ans = {l, r};
        res += a[++r];
        // cout << l << " " << r << " " << res << '\n';
    }
    if(ans.fi == 0)
        cout << -1;
    else 
        cout << ans.fi << " " << ans.se;
}

void init() {
    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
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