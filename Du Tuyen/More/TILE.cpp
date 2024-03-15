#include<bits/stdc++.h>

#define int int64_t
const int N = 1e5 + 9;

using namespace std;

int n, a[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n, greater<int>());
    int ans = 1, d = a[1];
    for(int i = 2; i <= n; i++) {
        if(!d)
            break;
        d--;
        d = min(d, a[i]);
        ans++;
    }
    cout << ans;
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define task "TILE"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    solve();
}