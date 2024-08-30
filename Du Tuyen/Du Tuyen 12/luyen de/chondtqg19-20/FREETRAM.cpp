#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
typedef long long ll;
typedef pair<int, ll> ii;

int n, m, k, be, ed;

vector<ii> adj[N];
vector<int> s[N];
vector<tuple<int, int, ll> > Edge;
vector<bool> b(N, false);

vector<ll> dijkstra(int x) {
    vector<ll> D;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    D.resize(n + 2, INT_MAX);
    vector<bool> P(n + 2, false);
    D[x] = 0;
    q.push({0, x});
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();

        if(P[u])
            continue;

        P[u] = 1;

        for(auto [v, w] : adj[u]) {
//            cout << "check: " << u << " " << v << " " << w << '\n';
            if(D[v] > D[u] + w) {
                D[v] = D[u] + w;
                q.push({D[v], v});
//                s[v] = s[u];
//                s[v].push_back(w);
//                sort(s[v].begin(), s[v].end());
//                while(s[v].size() > k)
//                    s[v].pop_back();
            }
        }
    }
    return D;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);


    cin >> n >> m >> k >> be >> ed;

    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        Edge.push_back({u, v, w});
    }

    vector<ll> xuoi = dijkstra(be), nguoc = dijkstra(ed);

    ll ans = LLONG_MAX;

    for(auto [u, v, w] : Edge) {
        ans = min(ans, min(xuoi[u] + nguoc[v], nguoc[u] + xuoi[v]));
    }

    cout << ans;
}

