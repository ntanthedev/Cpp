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
 
const int N = 1e5+10;
const ll MOD = 1e9+7;
 
bool is_prime(int x)
{
    for(int i = 2 ; i * i <= x ; i++)
        if(x%i == 0)
            return 0;
    return 1;
}
//----------------------------
ll m, n, ans = 0, gmax = 1;
ll par[N], sz[N];
//----------------------------
int find_sets(int x){
    if(par[x] == x)
        return x;
    else{
        int p = find_sets(par[x]);
        par[x] = p;
        return p;
    }
}
void make_sets(int v){
    par[v] = v;
    sz[v] = 1;
}
void union_sets(int a, int b){
    a = find_sets(a);
    b = find_sets(b);
    if(a != b){
        if(sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        gmax = max(gmax, sz[a]);
        ans--;
    }
}
void init(){
    cin >> n >> m;
    ans = n;
    for(int i = 1; i <= n; i++)
        make_sets(i);
    for(int i = 1; i <= m; i++){
        ll u, v;
        cin >> u >> v;
        //if(find_sets(u) != find_sets(v)){
            union_sets(u, v);
        //    ans--;
        //}
        cout << ans << " " << gmax << '\n';
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
    //solve();
}