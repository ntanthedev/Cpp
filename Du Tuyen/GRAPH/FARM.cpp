#include<bits/stdc++.h>
#define fi first
#define se second
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

const int N = 2e3+10;
const ll MOD = 1e9+7;

//----------------------------Khai Bao
ll n, m, c = 0, f = 0, cc, cf;
char a[N][N];
bool visited[N][N];
int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};
//----------------------------
bool check(int i, int j){
    if(visited[i][j])
        return false;
    if(i > m || i < 1 || j > n || j < 1)
        return false;
    if(a[i][j] == '#')
        return false;
    return true;
}
void dfs(int i, int j){
    visited[i][j] = true;
    if(a[i][j] == 'c')
        cc++;
    if(a[i][j] == 'f')
        cf++;
    for(int k = 0; k < 4; k++){
        int newx = j, newy = i;
        newx += nx[k];
        newy += ny[k];
        if(check(newy, newx))
            dfs(newy, newx); 
    }
}
void solve(){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(check(i,j)){
                //cout<<i<<" "<<j<<'\n';
                cc = 0;
                cf = 0;
                dfs(i, j);
                //cout<<"cf: "<<cf<<" "<<cc<<'\n';
                if(cf >= cc)
                    c -= cc;
                else
                    f -= cf; 
            }
            /*
            if(visited[i][j])
                cout<<1;
            else
                cout<<0;
            */
        } //cout<<'\n';
    }
    cout<<f<<" "<<c;
}

void init(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j]=='c')
                c++;
            if(a[i][j]=='f')
                f++;
            visited[i][j] = false;
        }
    //cout<<"dem: "<<f<<" "<<c<<'\n';
}
//-----TASK----------
#define task "FARM"
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