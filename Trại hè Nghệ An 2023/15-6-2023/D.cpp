#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

using namespace std;

template <typename T> inline void read (T &x) {
    bool b = 0;
    char c;
    while (!isdigit (c = getchar()) && c != '-');
    if (c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while (isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if (b) {
        x=-x;
    }
}

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 41;
const ll MOD = 1e9+7;

int m, n, d[N][N][N][N], a[N][N];
int dx[] = {1, -1, 0, 0},
    dy[] = {0, 0, 1, -1};
queue<ii> q;
void bfs(int x, int y){
    d[x][y][x][y] = 0;
    q.push(mp(x, y));
    while(!q.empty()){
        ii u = q.front(); q.pop();
        ii umin = {0, 0};
        int fmin = INT_MAX;
        bool flag = 0;
        for(int i = 0; i < 4; i++){
            int nx = u.fi + dx[i],
                ny = u.se + dy[i];
            if(nx > m || ny > n || nx < 1 || ny < 1)
                continue;
            if(d[x][y][nx][ny] == -1){
                if(abs(a[nx][ny] - a[u.fi][u.se]) <= fmin){
                    if(abs(a[nx][ny] - a[u.fi][u.se]) == fmin && abs(a[u.fi][u.se] - a[nx][ny]) < abs(a[umin.fi][umin.se] - a[u.fi][u.se]))
                        umin = mp(nx, ny);
                    fmin = a[nx][ny];
                }
                flag = 1;
            }
            //f(!flag)
            //    d[x][y][nx][ny] = -1;
        }
        q.push(umin);
    } 
}
void solve(){
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            bfs(i, j);
}

void init(){
    memset(d, -1, sizeof(d));
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    a[0][0] = INT_MAX;
}
#define task ""
int32_t main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        init();
        solve();
    }
}