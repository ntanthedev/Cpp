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
int n, m, s, t;
vi f[MAXN], ans;
unordered_map<int, bool> M;
bool flag = false;
//----------------------------
void dfs(int x){
    if(flag)
        return;
    M[x] = true;
    for(int v: f[x]){
        if(!M[v]){
            ans.pb(v);
            if(v == t){
                flag = true;
                return;
            }
            dfs(v);if(flag)
            return;
            ans.pop_back();
        }        
    }
}
void solve(){
    //for(int v:f[s]) cout<<v<<" "; cout<<'\n';
    for(int i = 1; i <= n; i++)
        sort(all(f[i]));
    ans.pb(s);
    dfs(s);
    for(int i:ans)
        cout<<i<<" ";
}

void init(){
    cin >> n >> m >> s >> t;
    int u, v;
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        f[u].pb(v);
    }
}
//-----TASK----------
#define task "DFS"
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