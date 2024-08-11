//problem "CSES1669"
//created in 12:32:59 - Wed 10/07/2024
 
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
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "a"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, m;
    
    cin >> n >> m;
 
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> trace(n + 1, -1), ans, res;
 
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);        
    }
 
    function<void(int, int)> dfs = [&](int u, int p) {
        // dbg(u, p)
        res.push_back(u);
        for(auto v : adj[u]) {
            if(v == p) continue;
 
            if(trace[v] != -1) {
                ans.push_back(v);
                for(auto it = res.rbegin(); it != res.rend(); it++) {
                    ans.push_back(*it);
                    if(*it == v) 
                        break;
                }
                // dbg(u)
                // dbg(v)
                // dbg(res)
                reverse(ans.begin(), ans.end());
                if(ans.size() == 50002)
                    ans.pop_back();
                cout << ans.size() << '\n';
                for(auto i : ans) 
                    cout << i << " ";
                exit(0);
            }
 
            trace[v] = u;
            
            dfs(v, u);
            
        } 
        
        res.pop_back();
    };
 
    for(int u = 1; u <= n; u++) {
        res.clear();
        if(trace[u] == -1)
            dfs(u, 0);
    }
 
    cout << "IMPOSSIBLE";
}