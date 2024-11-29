#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
using namespace std;

const int N = 1e3+10;

typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll m, n, Q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
ii b;
queue<ii> q;
int a[N][N];
ll d[N][N];
bool visited[N][N];
vii ans;
bool flag = 1;

bool check( int x2, int y2){ 
    if(x2 < 1 || y2 < 1 || x2 > m || y2 > n)    
        return false;
    return true;
}

void solve(){
    q.push(b);
    visited[b.fi][b.se] = true;
    while(!q.empty()){
        ii u = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            ll nx = u.fi + dx[i], ny = u.se + dy[i];
            if(check( nx, ny)){
                if(a[u.fi][u.se] != a[nx][ny] && d[nx][ny] + 1 < d[u.fi][u.se]){
                    flag = 0;
                    d[u.fi][u.se] = d[nx][ny] + 1;
                }
                if(a[u.fi][u.se] == a[nx][ny] && d[nx][ny] < d[u.fi][u.se]){
                    flag = 0;
                    d[u.fi][u.se] = d[nx][ny];
                }
                if(!visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push(mp(nx, ny));
                }
            }
        }
    }

    ii e;
    while(Q--){
        cin >> e.fi >> e.se;
        if(d[e.fi][e.se] != 1e18)
            cout << d[e.fi][e.se] << '\n';
        else
            cout << -1 << '\n';
    }

    // cout << "-----------\n";
    // for(int i = 1; i <= m; i++){
    //     for(int j = 1; j <= n; j++)
    //         if(d[i][j] == 1e18)
    //             cout << 9 << " ";
    //         else
    //             cout << d[i][j] << " ";
    //     cout << '\n';
    // }
}

void init(){
    cin >> m >> n >> Q;
    cin >> b.fi >> b.se; 
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            visited[i][j] = false;
            d[i][j] = 1e18;
        }
    d[b.fi][b.se] = 0;
}
#define task "MECUNG3"
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    init();
    solve();
    return 0;
}
