#include<bits/stdc++.h>

#define int int64_t
#define fi first
#define se second
const int N = 5e3 + 9;

using namespace std;

int n, a[N], b[N], c[N];

void solve() {
    sort(c + 1, c + 1 + n);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            int t = lower_bound(c + 1, c + 1 + n, a[i] + b[j]) - c - 1;
            int p = lower_bound(c + 1, c + 1 + n, abs(a[i] - b[j])) - c;
            ans += t - p + 1;
        }
    cout << ans;
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define task "BOBA2"
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) cin >> c[i];

    solve();
}
