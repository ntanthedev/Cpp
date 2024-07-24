// problem "MOTORBIKE"
// created in 09:36:35 - Wed 24/07/2024

#include <bits/stdc++.h>

#define int int64_t

using namespace std;

struct Edge {
    int id, x, y, k;
    bool q;

    Edge(int _id, int _x, int _y, int _k, bool _q) : id(_id), x(_x), y(_y), k(_k), q(_q) {}
};

int n, m, A, B;
pair<int, int> P, Q;
Edge adj[5000];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> P.first >> P.second;
    cin >> Q.first >> Q.second;
    cin >> A >> B;

    for(int i = 1; i <= m; ++i) {
        cin >> adj[i].x >> adj[i].y >> adj[i].k >> adj[i].q;
    }

    
}