#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
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

const int N = 1e6+10;
const ll MOD = 1e9+7;

bool is_prime(int x)
{
    for(int i = 2 ; i * i <= x ; i++)
        if(x%i == 0)
            return 0;
    return 1;
}
//----------------------------
ll n, m, s = 0;
//----------------------------
struct edge{
    ll u, w, v, id;
};

ll par[N];
int find(int u){
    if(par[u] < 0)
    return u;
    return par[u] = find(par[u]);
}
bool join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)
        return false;
    if(par[u] > par[v])
        swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true; 
}

edge ed[N];
vector<edge> f[N];
ll deep[N], ans, p[N][18], ma[N][18];
void dfs(int u, int pu){
    deep[u] = deep[pu] + 1;
    p[u][0] = pu;
    for(int i = 1; (1 << i) <= n; i++){
        p[u][i] = p[p[u][i-1]][i-1];
        //ma[u][i] = 
    }
}
void solve(){
    for(int i = 1; i <= n; i++)
        par[i] = -1;
    sort(ed+1, ed+1+m, [](edge &x, edge &y){
        return x.w < y.w;
    });
    for(auto e:ed){
        if(join(e.u, e.v))
            s += e.w;
    }
    deep[0] = 0;
    dfs(1, 0);
}

void init(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> ed[i].u >> ed[i].v >> ed[i].w;
        ed[i].id = i;
    }
}
//-----TASK----------
#define task "TASK"
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