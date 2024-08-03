//problem "aa"
//created in 12:27:14 - Fri 02/08/2024

#include<bits/stdc++.h>
#define fi first 
#define se second

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "COMNET"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj;
    
    vector<pair<int, int>> q(m + 1);

    for(int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        q[i] = {x, y};
    }

    function<bool(int)> check = [&] (int x) {
        adj.resize(n + 1, vector<int>(0));
        for(int i = 1; i <= x; ++i) {
            auto [u, v] = q[i];
            adj[u].push_back(v);
        }

        map<int, bool> m;
        queue<int> q;

        q.push(1); m[1] = 1;
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            for(auto v : adj[u]) {
                if(m.find(v) == m.end()) {
                    m[v] = 1;
                    q.push(v);
                }
            }
        }

        return m[n];
    };

    int l = 1, r = m, ans = -1;

    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else 
            l = mid + 1;
    }

    cout << ans;
}