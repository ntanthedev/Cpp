#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll N = 2e2 + 21;
const ll NN = 5e2 + 21;
ll a[N][N], ans = 0, n;
bool vis[N][N][NN];
pair<ll, ll> fa[N][N];
void dfs(ll x, ll y, ll p) {
    vis[x][y][p] = true;
    if(x == n && y == n)
        ans = max(ans, p);
    if(x > 1 && !vis[x - 1][y][p ^ a[x - 1][y]])
        dfs(x - 1, y, p ^ a[x - 1][y]);
    if(y > 1 && !vis[x][y - 1][p ^ a[x][y - 1]])
        dfs(x, y - 1, p ^ a[x][y - 1]);
    if(x < n && !vis[x + 1][y][p ^ a[x + 1][y]])
        dfs(x + 1, y, p ^ a[x + 1][y]);
    if(y < n && !vis[x][y + 1][p ^ a[x][y + 1]])
        dfs(x, y + 1, p ^ a[x][y + 1]);
}
void solve() {
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    dfs(1 * 1ll, 1 * 1ll, a[1][1]);
    cout << ans;
}

signed main() {
    #define task "code"
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}