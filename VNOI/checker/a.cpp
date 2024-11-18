#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define task "a"

using namespace std;

const int maxN = 5001;
int n, m;
vector<int> adj[maxN];
int d[maxN][maxN];
queue<ii> q;
ii trace[maxN][maxN];

void bfs() {
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        for (int x1 : adj[u.fi]) {
            for (int y1 : adj[u.se]) {
                if (d[x1][y1] != -1) continue;
                d[x1][y1] = d[u.fi][u.se] + 1;
                trace[x1][y1] = u;
                if (x1 == 1 && y1 == n) return;
                q.push({x1, y1});
            }
        }
    }
}

void trace_path() {
    vector<int> path1, path2;
    ii u = {1, n};
    while (true) {
        path1.push_back(u.fi);
        path2.push_back(u.se);
        if (u.fi == u.se) break;
        u = trace[u.fi][u.se];
    }
//    reverse(path1.begin(), path1.end());
//    reverse(path2.begin(), path2.end());
    for (int i : path1) cout << i << " ";
    cout << '\n';
    for (int i : path2) cout << i << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }

    fill(&d[0][0], &d[n + 1][0], -1);
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
        q.push({i, i});
    }

    bfs();
    cout << d[1][n] << '\n';
    if (d[1][n] != -1) {
        trace_path();
    }

    return 0;
}
