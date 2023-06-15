#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll N = 42;
const ll inf = 1e18;

ll d[N][N][N][N], m, n, ans, val;
ll a[N][N], ck[N][N];
vector<ii> vt[N][N][N][N];

ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};

void get(ll x, ll y) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ck[i][j] = 0;
            ll res = inf;
            ii v;
            if(i == x && j == y)
                continue;
            for(int k = 0; k < 4; k++) {
                ll x1 = i + dx[k];
                ll y1 = j + dy[k];

                if(x1 < 1 || y1 < 1 || x1 > n || y1 > m)
                    continue;
                if(res > abs(a[x][y] - a[x1][y1])) {
                    res = abs(a[x][y] - a[x1][y1]);
                    v = {x1, y1};
                } else {
                    if(res == abs(a[x][y] - a[x1][y1]) &&
                       (abs(a[i][j] - a[x1][y1]) <
                        abs(a[i][j] - a[v.fi][v.se]))) {
                        v = {x1, y1};
                    }
                }
            }
            vt[x][y][v.fi][v.se].push_back({i, j});
        }
    }

    queue<ii> q;
    q.push({x, y});
    d[x][y][x][y] = 0;
    ck[x][y] = 1;
    while(q.size()) {
        auto v1 = q.front();
        q.pop();

        for(auto v2: vt[x][y][v1.fi][v1.se]) {
            if(ck[v2.fi][v2.se])
                continue;
            d[x][y][v2.fi][v2.se] = d[x][y][v1.fi][v1.se] + 1;
            ck[v2.fi][v2.se] = 1;
            q.push(v2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for(int x1 = 1; x1 <= n; x1++) {
        for(int y1 = 1; y1 <= m; y1++) {
            for(int x2 = 1; x2 <= n; x2++) {
                for(int y2 = 1; y2 <= m; y2++) {
                    d[x1][y1][x2][y2] = inf;
                }
            }
        }
    }

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            get(i, j);
        }
    }

    ans = inf;

    for(int x1 = 1; x1 <= n; x1++) {
        for(int y1 = 1; y1 <= m; y1++) {
            ll res = -inf;
            for(int x2 = 1; x2 <= n; x2++) {
                for(int y2 = 1; y2 <= m; y2++) {
                    res = max(res, d[x2][y2][x1][y1]);
                }
            }
            if(ans > res) {
                ans = res;
                val = a[x1][y1];
            }
        }
    }

    if(ans == inf) {
        cout << -1;
    } else
        cout << val << " " << ans;
}