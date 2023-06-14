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
ll m, n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
    //U - D - R - L;
ii b;
queue<ii> q;
int a[N][N], trace[N][N];
bool visited[N][N];
vii ans;
//----------------------------
bool check(int x, int y){
    if(a[x][y] || visited[x][y])
        return false;
    return true;
}
void solve(){
    q.push(b);
    visited[b.fi][b.se] = true;
    while(!q.empty()){
        ii u = q.front(); q.pop();
        if(u.fi == m || u.se == n || u.fi == 1 || u.se == 1){
            while(u != b){
                ll k = trace[u.fi][u.se];
                ans.eb(mp(u.fi, u.se));
                u.fi -= dx[k];
                u.se -= dy[k];
            }
            ans.eb(mp(u.fi, u.se));
            reverse(all(ans));
            cout << ans.size() << '\n';
            for(auto i : ans)
                cout << i.fi << " " << i.se << '\n';
            return;
        }
        for(int i = 0; i < 4; i++){
            ll nx = u.fi + dx[i], ny = u.se + dy[i];
            if(check(nx, ny)){
                q.push(mp(nx, ny));
                trace[nx][ny] = i;
                visited[nx][ny] = true;
            }
        }
    }
    cout << 0;
}

void init(){
    cin >> m >> n;
    cin >> b.fi >> b.se;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            visited[i][j] = false;
        }
}
//-----TASK----------
#define task "MECUNG"
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