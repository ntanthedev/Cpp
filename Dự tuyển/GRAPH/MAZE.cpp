#include<bits/stdc++.h>
#define fi first 
#define se second
#define mp make_pair 

#define fo(a, b, c) for(int a = b; a <= c; ++a)

const long long N = 5e3+9;
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int m, n, ans = 1e9;
int a[N][N];
char c;
vector<ii> water;
int water_time[N][N], human_time[N][N];
bool water_vis[N][N];
ii be;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool check(int x, int y, int newx, int newy) {
    if(a[newx][newy] == 0)
        return false;
    if(water_time[newx][newy] <= water_time[x][y])
        return false;
    if(newx > m || newx < 1 || newy > n || newy < 1)
        return false;
    if(water_vis[newx][newy])
        return false;
    return true;
}

bool human_check(int x, int y, int newx, int newy) {
    if(a[newx][newy] != 1)
        return false;
    if(human_time[newx][newy] != 1e9)
        return false;
    if(water_time[newx][newy] <= human_time[x][y])
    if(newx > m || newx < 1 || newy > n || newy < 1)
        return false;
    return true;
}

void bfs(ii x) {
    queue<ii> q;
    q.push(x);  
    water_time[x.fi][x.se] = 0;
    water_vis[x.fi][x.se] = 1;
    while(!q.empty()) {
        ii u = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = u.fi + dx[i];
            int ny = u.se + dy[i];
            if(check(u.fi, u.se, nx, ny)) {
                q.push(mp(nx, ny));
                water_vis[nx][ny] = 1;
                water_time[nx][ny] = water_time[u.fi][u.se] + 1;
            }
        }
    }
}

void solve() {
    for(vector<ii>::iterator i = water.begin(); i != water.end(); i++) 
        bfs(*i);
    
    queue<ii> q;
    q.push(be);
    human_time[be.fi][be.se] = 0;
    while(!q.empty()) {
        ii u = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = u.fi + dx[i];
            int ny = u.se + dy[i];
            if(human_check(u.fi, u.se, nx, ny)) {
                q.push(mp(nx, ny));
                human_time[nx][ny] = human_time[u.fi][u.se] + 1;
                if(nx == 1 || nx == m || ny == 1 || ny == n) {
                    ans = min(ans, human_time[nx][ny]);
                }
            }
        }
    }
    cout << ans;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("MAZE.inp","r")){
        freopen("MAZE.inp","r",stdin);
        freopen("MAZE.out","w",stdout);
    }
    cin >> m >> n;
    fo(i, 1, m) {
        fo(j, 1, n) {
            cin >> c;
            if(c == 'X')
                a[i][j] = 0;
            if(c == 'O')
                a[i][j] = 1;
            if(c == 'E') {
                a[i][j] = 2;
                be = mp(i, j);
            }
            if(c == 'S') {
                water.push_back(mp(i, j));
                a[i][j] = 3; 
            }
            water_time[i][j] = 1e9;
            water_vis[i][j] = false;
            human_time[i][j] = 1e9;
        }
    }
    solve();
}