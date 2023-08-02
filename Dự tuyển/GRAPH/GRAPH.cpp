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

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e5+10;
const ll MOD = 1e9+7;

int n, m;
bool joint[N], vis[N];
int timeDfs = 0, bridge = 0, tplt = 0;
int low[N], num[N];
vi f[N];

void dfs1(int x) {
    vis[x] = true;
    for(auto j : f[x])
        dfs1(j);
}

void dfs(int u, int pre) {
    int child = 0;
    num[u] = low[u] = ++timeDfs;
    for(auto v : f[u]) {
        if(v == pre) continue;
        if(!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] == num[v]) 
                bridge++;
            child++;
            if(u == pre) {
                if(child > 1)
                    joint[u] = true;
            }
            else if (low[v] >= num[u])
                joint[u] = true;
        }
        else 
            low[u] = min(low[u], num[v]);
    }
}

void solve() {
    for(int i = 1; i <= n; i++) {
        if(!num[i])
            dfs(i, i);
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            tplt++;
            dfs1(i);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!joint[i]) 
            cout << tplt << '\n';
    }
}

void init() {
    cin >> n >> m;
    while(m--) {
        int u,v;
        cin >> u >> v;
        f[u].eb(v);
        f[v].eb(u);
    }
}
#define task ""
int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
}