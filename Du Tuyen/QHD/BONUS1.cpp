// problem "BONUS1"
// created in 20:58:48 - Sun 14/04/2024

#include <bits/stdc++.h>

#define int int64_t
const int N = 1e3 + 9;

using namespace std;

int n, k;
int a[N][N];
int f[N][N], ans = 0;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define task "BONUS1"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    for(int i = 1; i <= n; i++)
        f[i][0] = 0, f[0][i] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];

    for(int i = k; i <= n; i++)
        for(int j = k; j <= n; j++) {
            ans = max(ans, f[i][j] - f[i - k][j] - f[i][j - k] + f[i - k][j - k]);
        }

    cout << ans;
}