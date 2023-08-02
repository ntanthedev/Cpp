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
        x = x * 10 + (c - 48);
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

const int MAXN = 1e5+10;
const ll MOD = 1e9+7;

bool is_prime(int x)
{
    for(int i = 2 ; i * i <= x ; i++)
        if(x%i == 0)
            return 0;
    return 1;
}
//----------------------------Khai Bao
int n, m;
vi f[MAXN];
unordered_map<int, int> M;
//----------------------------
void dfs(int x){
    M[x] = true;
    cout<<x<<" ";
    for(int v: f[x]){
        if(!M[v])
            dfs(v);
    }
}
void solve(){
    for(int i = 1; i <= n; i++){
        if(!M[i]){
            dfs(i);
            cout<<'\n';
        }
    }
}   

void init(){
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        f[u].eb(v);
        f[v].eb(u);
    }
}
//-----TASK----------
#define task "CONNECT"
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