#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 10;

long long t, a[N], n, k, ans = 0, mod = 1e9;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (j - i + 1 > k || j - i + 1 < k) continue;
            long long res = 1;
            for (int k = i; k <= j; ++k) {
                res = (res % mod * a[k]) % mod;
            }
            ans = max(res, ans);
        }
    }
    cout << ans << '\n';
    ans = 0;
}
int32_t main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> t;
    while (t--) solve();

}