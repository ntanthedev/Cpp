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
ii b;
int trace[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
     //U - D - R - L;
char dz[4] = {'S', 'N', 'E', 'W'};
bool visited[N][N];
char a[N][N];
vector<char> ans;
queue<ii> q;
//----------------------------
bool check(int x, int y){
    if(a[x][y] == '#' || visited[x][y])
        return false;
    return true;
}
void solve(){
    q.push(b);
    visited[b.fi][b.se] = true;
    while(!q.empty()){
        ii u = q.front(); q.pop();
        //if(visited[4][6])   cout << 1 << " ";
        //else cout << 0 << " " << a[4][6] <<" ";
        //cout << u.fi << " " << u.se << " " << trace[u.fi][u.se] << '\n';
        for(int i = 0; i < 4; i++){
            ll nx = u.fi + dx[i], ny = u.se + dy[i];
            //if(u.fi == 4 && u.se == 7)  cout << "check: " << nx << " " << ny<<'\n';
            if(check(nx, ny)){
                //if(u.fi == 4 && u.se == 7)  cout << "ok: " << nx << " " << ny<<'\n';
                q.push(mp(nx, ny));
                visited[nx][ny] = true;
                trace[nx][ny] = i;
            }
        }
        if(u.fi == m || u.se == n || u.fi == 1 || u.se == 1){
            //cout<<"YES1\n";
            while(u != b){
                ll k = trace[u.fi][u.se];
                ans.pb(dz[k]);
                u.fi -= dx[k];
                u.se -= dy[k];
            }
            //cout<<"YES2\n";
            reverse(all(ans));
            //cout<<"YES3\n";
            for(auto i : ans)
                cout << i;
            //cout<<"YES4\n";
            return;
        }
    }
}

void init(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == '*')
                b = mp(i, j);
            visited[i][j] = false;
        }
    //cout << b.fi << " " << b.se;
}
//-----TASK----------
#define task "LABYRINTH"
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