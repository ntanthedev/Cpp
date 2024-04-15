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
pair<int, int> h[3000009];

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
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];

    for(int i = 1; i <= k; i++)
        cin >> h[i].x >> h[i].y;

    sort(h + 1, h + 1 + k);

    cout << "\x1b[31mstart debug: \n";
    for(int i = 1; i <= k; i++) 
        cout << h[i].x << " " << h[i].y << '\n';
    // cerr << ;
    cout << "end of debug\e[39m \n";


    for(int i = 1; i <= k; i++) {
        ans += cal(h[i].x, h[i].y, h[i].x + r - 1, h[i].y + r - 1);
        // cout << h[i].x << " " << h[i].y << " " << h[i].x + r - 1 << " " << h[i].y + r - 1 << " " << cal(h[i].x, h[i].y, h[i].x + r - 1, h[i].y + r - 1) << " 1\n"; 
        if(i > 1 && h[i].x <= h[i - 1].x + r - 1 && h[i].y <= h[i - 1].y + r - 1)
            ans -= cal(h[i].x, h[i].y, h[i - 1].x + r - 1, h[i - 1].y + r - 1);
        // cout << h[i].x << " " << h[i].y << " " << h[i - 1].x + r - 1 << " " << h[i - 1].y + r - 1 << " " << cal(h[i].x, h[i].y, h[i - 1].x + r - 1, h[i - 1].y + r - 1) << " 2\n";
    }

    cout << ans;
}