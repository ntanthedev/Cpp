//created in 2024-08-29-09.39.05 in Code::Blocks 20.03
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
typedef long long ll;
typedef pair<ll, ll> ii;

int n, m, k, be, ed;

vector<ii> adj[N];
vector<int> s[N];
priority_queue<ii, vector<ii>, greater<ii>> q;
vector<ll> D;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("FREETRAM.inp","r",stdin);
    freopen("FREETRAM.out","w",stdout);

    cin >> n >> m >> k >> be >> ed;

    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    D.resize(n + 2, INT_MAX);
    vector<bool> P(n + 2, false);
    D[be] = 0;
    q.push({0, be});

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
                s[v] = s[u];
                s[v].push_back(w);
                sort(s[v].begin(), s[v].end());
                while(s[v].size() > k)
                    s[v].pop_back();
                q.push({D[v], v});
            }
        }
    }

//    for(int i = 1; i <= n; i++) cout << D[i] << " "; cout << '\n';

    ll res = 0;
    for(auto i : s[ed])
        res += i;
    cout << D[ed] - res;
}

