#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define int long long
using namespace std;
int new_x, new_y, hx[4] = {0, 0, -1, 1}, hy[4] = {1, -1, 0, 0}, x, y, n, m, q1,
                  q2, f[1002][1002], a[1002][1002];
long long t;
bool check[1002][1002];
queue<pair<int, int>> q;
void bfs() {
    q.push({x, y});
    f[x][y] = 0;
    while(!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            new_x = u.first + hx[i];
            new_y = u.second + hy[i];

            if(new_x < 1 || new_x > n || new_y < 1 || new_y > m)
                continue;
            if(a[new_x][new_y] != a[u.first][u.second] && f[new_x][new_y] > f[u.first][u.second] + 1) {
                q.push({new_x, new_y});
                f[new_x][new_y] = f[u.first][u.second] + 1;
            }
            if(a[new_x][new_y] == a[u.first][u.second] && f[new_x][new_y] > f[u.first][u.second]) {
                q.push({new_x, new_y});
                f[new_x][new_y] = f[u.first][u.second];
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mecung3.inp", "r", stdin);
    freopen("mecung3.out", "w", stdout);
    cin >> n >> m >> t;
    cin >> x >> y;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            f[i][j] = LLONG_MAX - 5;
        }
    }
    bfs();
    while(t--) {
        cin >> q1 >> q2;
        cout << f[q1][q2] << "\n";
    }
}
