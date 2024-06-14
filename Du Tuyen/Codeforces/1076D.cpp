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
vector<int> D, ans;
vector<bool> P;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m >> k;
    f.resize(n + 1, vector<Edge>());
    D.resize(n + 1, INT_MAX);
    P.resize(n + 1, false);

    for(int i = 1, x, y, w; i <= m; i++) {
        cin >> x >> y >> w;
        f[x].push_back({y, w, i});
        f[y].push_back({x, w, i});
    }

    D[1] = 0;
    q.push({D[1], 1});

    while(!q.empty()) {
        auto u = q.top().se;
        q.pop();

        if(P[u])
            continue;

        P[u] = 1;
        for(auto [v, w, id] : f[u]) {
            if(D[u] + w < D[v]) {
                D[v] = D[u] + w;
                ans.push_back(id);
                q.push({D[v], v});
            }
        }
    }

    // for(int i = 1; i <= 3; i++) 
    //     cout << D[i] << " ";

    k = min(k, int(ans.size()));
    cout << k << '\n';
    for(int i = 0; i < k; i++) 
        cout << ans[i] << " ";
}