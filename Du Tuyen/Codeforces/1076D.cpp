//problem "1076D"
//created in 19:36:54 - Fri 14/06/2024

#include<bits/stdc++.h>

#define int int64_t
#define fi first 
#define se second

using namespace std;

int k, n, m;

struct Edge {
    int v, w, id;
};

vector<vector<Edge>> f;
vector<pair<int, int>> D;
vector<bool> P;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m >> k;
    f.resize(n + 1, vector<Edge>());
    D.resize(n + 1, {1e18, 0});
    map<int, int> ans;
    P.resize(n + 1, false);

    for(int i = 1, x, y, w; i <= m; i++) {
        cin >> x >> y >> w;
        f[x].push_back({y, w, i});
        f[y].push_back({x, w, i});
    }

    D[1].fi = 0;
    q.push({0, 1});

    while(!q.empty()) {
        auto u = q.top().se;
        q.pop();

        if(P[u])
            continue;

        P[u] = 1;
        for(auto [v, w, id] : f[u]) {
            if(D[u].fi + w < D[v].fi) {
                D[v].fi = D[u].fi + w;
                // cout << "check: " << u << " " << v << " " << id << '\n';
                D[v].se = id;
                q.push({D[v].fi, v});
            }
        }
    }

    // for(int i = 1; i <= 3; i++) 
    //     cout << D[i] << " ";

    k = min(k, n - 1);
    cout << k << '\n';
    sort(D.begin() + 1, D.end());

    for(int i = 2; i <= k + 1; i++) 
        cout << D[i].se << " ";
}