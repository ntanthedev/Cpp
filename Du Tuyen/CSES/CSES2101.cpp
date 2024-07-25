//problem "CSES2101"
//created in 15:46:47 - Mon 22/07/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m, q;
    
    cin >> n >> m >> q;

    vector<int> par(n + 1);
    vector<vector<int> > time(n + 1, vector<int>());
    vector<pair<int, int>> adj(m + 1), query(q + 1), range(q + 1);

    function<int(int)> find_par = [&](int x) {
        return par[x] < 0 ? x : par[x] = find_par(par[x]);
    };

    function<void(int, int)> merge_par = [&](int a, int b) {
        int a = find_par(a);
        int b = find_par(b);

        if(a != b) {
            if(par[a] > par[b])
                swap(a, b);
            par[a] += par[b];
            par[b] = a;
        }
    };

    function<bool(int, int, int)> check = [&](int mid, int u, int v) {
        for(int i = 1; i <= mid; i++) {
            
        }
    };

    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adj[i] = {u, v};
    }

    for(int i = 1, u, v; i <= q; i++) {
        cin >> u >> v;
        query[i] = {u, v};
        range[i] = {1, n};
    }

    for(int i = 1; i <= q; i++) {
        auto [l, r] = range[i];
        auto [u, v] = query[i];

        while(l <= r) {
            int mid = (l + r) >> 1;
            
        }
    }
}