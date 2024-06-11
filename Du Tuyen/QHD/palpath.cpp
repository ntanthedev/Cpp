#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
ll f[501][501][501], n, res, xx, yy, x, y;
char a[501][501];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    if(a[1][1] != a[n][n]) {
        cout << 0;
        return 0;
    }
    f[0][1][n] = 1;
    for(int len = 1; len <= n - 1; len++) {
        for(int x = 1; x <= n; x++) {
            y = len - x + 2;
            if(y < 1 || n < y)
                continue;
            for(int xx = n; xx >= x; xx--) {
                yy = 2 * n - xx - len;
                if(yy < 1 || n < yy || a[x][y] != a[xx][yy])
                    continue;
                f[len][x][xx] = (f[len - 1][x][xx] + f[len - 1][x - 1][xx + 1] + f[len - 1][x - 1][xx] + f[len - 1][x][xx + 1]) % MOD;
                if(len == n - 1 && x == xx) {
                    res = (res + f[len][x][xx]) % MOD;
                }
            }
        }
    }
    cout << res;
}
