//problem "CRARR"
#include<bits/stdc++.h>

#define int long long

using namespace std;
const int N = 1e5 + 9;

int k, n, ans = 0;
vector<int> adj[N];
vector<int> f(N, 1);

int dfs(int u) {
    
    for(int v : adj[u]) {
        f[u] += dfs(v);    
    }

    if(f[u] >= k) 
        ans++, f[u] = 0;

    return f[u];
} 

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "CRARR"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> k >> n;

    for(int i = 2, u; i <= n; i++) {
        cin >> u;
        adj[u].push_back(i);
    }
    
    int res = dfs(1);

    cout << ans;
}