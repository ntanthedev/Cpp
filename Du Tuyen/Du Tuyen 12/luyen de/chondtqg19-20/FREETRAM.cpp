//created in 2024-08-31-14.37.03 in Code::Blocks 20.03
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
typedef pair<long long, int> ii;
typedef long long ll;

int n, m, be, ed, k;
ll dp[N][6];
vector<ii> adj[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> k >> be >> ed;

    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> D(n + 2, LLONG_MAX);
    vector<bool> P(n + 2, false);
    priority_queue<ii, vector<ii>, greater<ii>> q;
    for(int i = 1; i <= n + 2; i++)
        for(int j = 0; j <= k; j++)
            dp[i][j] = 1e18;

    q.push({0, be});
    D[be] = 0;
    dp[be][0] = 0;

    while(!q.empty()) {
        int u = q.top().second;
        q.pop();

        if(P[u])
            continue;

        P[u] = 1;

        for(auto [v, w] : adj[u]) {
            if(D[v] > D[u] + w) {
                D[v] = D[u] + w;
                q.push({D[v], v});
                dp[v][0] = dp[u][0] + w;
                for(int i = 1; i <= k; i++) {
                    dp[v][i] = min({dp[v][i], dp[u][i - 1], dp[u][i] + w});
                }
            }
        }
    }

    ll ans = LLONG_MAX;
    for(int i = 0; i <= k; i++)
        ans = min(ans, dp[ed][i]);
    cout << ans;
}
