#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
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

typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e3+10;
const ll MOD = 1e9+7;

bool is_prime(int x)
{
    for(int i = 2 ; i * i <= x ; i++)
        if(x%i == 0)
            return 0;
    return 1;
} 
//----------------------------
ll n, m, a[N][N], Q, ans = 0;
bool visited[N][N], v1[N][N];
ii b, e;
queue<ii> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
//----------------------------
bool check(int x, int y){
    if(visited[x][y] || x < 1 || y < 1 || x > m || y > n)
        return false;
    return true;
}
void bfs(int x, int y){
    q.push(mp(x, y)); visited[x][y] = true;
    while(!q.empty()){
        for(int i = 0; i < 4; i++){
            int nx = q.front().fi + dx[i];
            int ny = q.front().se + dy[i];
            if(check(nx, ny)){
                q.push(mp(nx, ny));
                visited[nx][ny] = true;
            }
        }
        q.pop();
    }
}
void solve(){
    while(Q--){
        read(b.fi), read(b.se);
        read(e.fi), read(e.se);
        if(b.fi == e.fi)
            for(int i = min(b.se, e.se); i <= max(b.se, e.se); i++){
                visited[b.fi][i] = true;
                //v1[b.fi][i] = 1;
            }
        else
            for(int i = min(b.fi, e.fi); i <= max(b.fi, e.fi); i++){
                visited[i][b.se] = true;
                //v1[i][b.se] = 1;
            }
    }
    // cout << "------------\n";
    // for(int i = 1; i <= m; i++){
    //     for(int j = 1; j <= n; j++){
    //         if(visited[i][j])
    //             cout<<"*";
    //         else
    //             cout<<".";
    //     }
    //     cout << '\n';
    // }
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            if(check(i, j)){
                ans++;
                bfs(i, j);
            }
        }
    cout << ans ;
}

void init(){
    read(m), read(n), read(Q);
}
//-----TASK----------
#define task "SOVUNG"
//-------------------
int32_t main(){
    //---------------------------------
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    //---------------------------------
    init();
    solve();
}