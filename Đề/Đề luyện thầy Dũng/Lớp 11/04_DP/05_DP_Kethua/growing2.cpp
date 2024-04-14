#include <bits/stdc++.h>

using namespace std;

int n, m, d;
long long h[505][505];
long long a[505][505];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> d;
    for (int i = 1; i <= d; ++i) {
        int l, r, u, v, k;
        cin >> l >> r >> u >> v >> k;
        h[l][u] += k;
        h[r+1][u] -= k;
        h[l][v+1] -= k;
        h[r+1][v+1] += k;
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + h[i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
