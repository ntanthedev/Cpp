//problem "FISH"
//created in 08:50:21 - Wed 14/08/2024

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e3 + 3;

struct Edge {
    int v, w;
    bool t;
};

int n;
ld f[N];
vector<Edge> adj[N];

int cal(int x, int m) {
    return ld(m / 100.0000) * x;
}

ld dp(int u, double D, bool T) {
    ld ans;
    if(f[u] != -1) {
        if(T)
            f[u] = sqrt(f[u]);
        return f[u] / D * 100.0000;
    }
    
    f[u] = 0;
    for(auto [v, w, t] : adj[u]) {
        f[u] = max(f[u], dp(v, w, t));
    }

    if(T)
        f[u] = sqrt(f[u]);
    return f[u] / D * 100.0000;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "FISH"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n;

    for(int i = 1, u, v, w; i < n; i++) {
        bool t;
        cin >> u >> v >> w >> t;
        adj[u].push_back({v, w, t});
    }

    for(int i = 1; i <= n; i++) 
        cin >> f[i];

    cout << fixed << setprecision(4) << dp(1, 100, 0);
}