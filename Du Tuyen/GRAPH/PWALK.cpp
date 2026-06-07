//problem "PWALK"
//created in 22:58:24 - Sat 08/11/2025

#include<bits/stdc++.h>

// #define int int64_t
#define fi first 
#define se second

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, q;

    cin >> n >> q;

    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
    vector<int> h(n + 1);
    vector<vector<int>> dis(n + 1, vector<int>(11)), par(n + 1, vector<int>(11));

    for(int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    function<void(int)> dfs = [&] (int u) {
        for(auto [v, w] : adj[u]) {
            if(v == par[u][0]) 
                continue;
            h[v] = h[u] + 1;
            par[v][0] = u;
            dis[v][0] = w;
            dfs(v);
        }
    };

    function<int(int, int)> lca = [&] (int u, int v) {
        if(h[u] < h[v]) 
            swap(u, v);
        
        int k = h[u] - h[v];
        for(int i = 0; i <= __lg(k); i++) 
            if((k >> i) & 1)
                u = par[u][i];
        
        if(u == v) 
            return u;
        
        dbg(u, v);
        
        for(int i = 10; i >= 0; i--) {
            if(par[u][i] != par[v][i]) 
                u = par[u][i], v = par[v][i];
        }

        return par[u][0];
    };

    h[1] = 1;
    par[1][0] = 0;
    dfs(1);

    for(int i = 1; i <= __lg(n); i++) {
        for(int u = 1; u <= n; u++) {
            par[u][i] = par[par[u][i - 1]][i - 1];
            dis[u][i] = dis[par[u][i - 1]][i - 1] + dis[u][i - 1];
        }
    }

    function<int(int, int)> cal = [&](int u, int p) {

        int k = h[u] - h[p];
        int res = 0;

        for(int i = 0; i <= __lg(k); i++) {
            if((k >> i) & 1) {
                res += dis[u][i];
                u = par[u][i];
            }
        }

        return res;
    };

    while(q--) {
        int u, v;

        cin >> u >> v;

        int p = lca(u, v);
        // dbg(p);

        cout << cal(u, p) + cal(v, p) << '\n';
    }
}