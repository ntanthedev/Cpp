#include <bits/stdc++.h>
using namespace std;
#define task "SDKEQ"
const int N = 1e6 + 9;
typedef long long ll;
ll n, k, a[N], f[N], s[N], ans[N], m;
void solve() {

    for(int j = 2; j <= k; j++) {
        m = 0, ans[j - 1] = LLONG_MIN;
        for(int i = j; i <= n; i++) {
            ans[i] = max(ans[i - 1], s[i] - m);
            m = min(m, s[i] - f[i]);
            f[i] = ans[i];
        }
    }
    cout << ans[n];
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    f[0] = LLONG_MIN;
    for(int i = 1; i <= n; i++) {
        f[i] = max(f[i - 1], s[i] - m);
        ans[i] = f[i];
        m = min(m, s[i]);
    }
    solve();
}