#include<bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e3+10;
const ll MOD = 1e9+7;

int m, n, a[N][N], h[N][N];
bool vis[N][N];
int dx[] = {1, -1, 0, 0},
    dy[] = {0, 0, 1, -1};

bool check1(ii x, ii y) {
    if(y.fi < 1 || y.fi > m || y.se < 1 || y.se > n || vis[y.fi][y.se])
        return false;
    if(a[y.fi][y.se] >= a[x.fi][x.se])
        return true;
    else
        return false;
}

bool check(ii x, ii y) {

}

void bfsngoai(ii x) {
    queue<ii> q;
    q.push(x);
    vis[x.fi][x.se] = true;

    while(!q.empty()) {
        ii u = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            ii nxy = mp(u.fi + dx[i], u.se + dy[i]);
            if(check1(u, nxy)) {
                q.push(nxy);
                vis[nxy.fi][nxy.se] = true;
            }
        }
    }
}

void bfs(ii x) {
    queue<ii> q;
    q.push(x);

    while(!q.empty()) {
        ii u = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            ii nxy = mp(u.fi + dx[i], u.se + dy[i]);
            if(check(u, nxy)) {
                q.push(nxy);
                vis[nxy.fi][nxy.se] = true;
            }
        }
    }
}

void solve() {
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j += n-1)
            if(!vis[i][j])
                bfsngoai(mp(i, j));

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j += m-1)
            if(!vis[j][i])
                bfsngoai(mp(j, i));

    for(int i = 2; i < m; i++) {
        for(int j = 2; j < n; j++) {
            if(!vis[i][j])
                bfs(mp(i, j));
        }
    }
}

void init() {
    cin >> m >> n;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            vis[i][j] = false;
            h[i][j] = 1e9;
        }
    }
}

#define task "MOHINH"
int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
}
