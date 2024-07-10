//problem "a"
//created in 17:20:55 - Tue 09/07/2024

#include<bits/stdc++.h>

// #define int int64_t

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

vector<int> dijkstra(int s, int n, vector<vector<pair<int, int>>> adj) {

    vector<int> D(n + 1, INT_MAX);
    vector<bool> P(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    D[s] = 0;

    q.push({0, s});

    while(!q.empty()) {
        int u = q.top().second; q.pop();

        if(P[u])
            continue;
        
        P[u] = 1;

        for(auto [v, w] : adj[u]) {
            if(D[v] > D[u] + w) {
                D[v] = D[u] + w;
                q.push({D[v], v});
            }
        }
    }

    return D;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>()), adj2(n + 1, vector<pair<int, int>>());
    
    for(int i = 1, u, k, v; i <= m; i++) {
        cin >> u >> v >> k;
        adj[u].emplace_back(v, k);
        adj2[v].emplace_back(u, k);
        // adj[v].emplace_back(u, k);
    }

    // cout << "hio"; exit(0);
    vector<int> D_1 = dijkstra(1, n, adj), D_n = dijkstra(n, n, adj2);

    // dbg(D_1); dbg(D_n);

    int ans = INT_MAX;

    for(int u = 1; u <= n; u++) {
        for(auto [v, w] : adj[u]) {
            if(D_1[u] == INT_MAX || D_n[v] == INT_MAX)
                continue;
            ans = min(D_1[u] + w/2 + D_n[v], ans);            
        }
    }

    cout << ans;
}