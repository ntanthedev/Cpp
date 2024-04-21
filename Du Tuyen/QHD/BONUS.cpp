// problem "BONUS"
// created in 21:56:06 - Sun 14/04/2024

#include <bits/stdc++.h>

#define int int64_t
#define x first
#define y second
const int N = 1e3 + 9;

using namespace std;

int n, r, k, ans = 0;
int a[N][N], f[N][N];
int b[N][N];

int cal(int x1, int y1, int x2, int y2) {
    x2 = min(x2, n);
    y2 = min(y2, n);
    return f[x2][y2] - f[x2][y1 - 1] - f[x1 - 1][y2] + f[x1 - 1][y1 - 1];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define task "BONUS"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> r >> k;

    for(int i = 1; i <= n; i++)
        f[i][0] = 0, f[0][i] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j],
            b[i][j] = 0;

    for(int i = 1; i <= k; i++) {
        int x, y; 
        cin >> x >> y;
        b[x][y] += 1;
        b[x + r][y] -= 1;
        b[x][y + r] -= 1;
        b[x + r][y + r] += 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i - 1][j - 1] + b[i][j]; 
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) 
    //         cout << f[i][j] << " " ;
    //     cout << '\n';
    // }

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            ans += (f[i][j] > 0) * a[i][j];

    cout << ans;
}