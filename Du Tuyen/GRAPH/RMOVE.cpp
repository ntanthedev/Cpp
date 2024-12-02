// problem "RMOVE"
// created in 02:56:27 - Tue 03/12/2024

#include <bits/stdc++.h>

#define int int64_t

using namespace std;

typedef pair<int, int> ii;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#define task "RMOVE"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, m;

    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if(n == 1)
        return cout << 0 << '\n' << 1 << '\n' << 1, 0;

    queue<ii> q;

    q.push({1, n});
    vector<bool> vis(n + 1, 0);
    vector<int> trace1(n + 1, 0), trace2(n + 1, 0);
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(int i: adj[x]) {
            for(int j: adj[y]) {
                if(dist[i][j] != -1) {
                    if(i == j) {
                        vector<int> path1, path2;
                        while(i != 1) {
                            path1.push_back(i);
                            i = trace1[i];
                        }
                        path1.push_back(1);

                        while(j != n) {
                            path2.push_back(j);
                            j = trace2[j];
                        }
                        path2.push_back(n);

                        reverse(path1.begin(), path1.end());
                        reverse(path2.begin(), path2.end());

                        cout << path1.size() << '\n';
                        for(int z: path1)
                            cout << z << ' ';
                        cout << '\n';
                        for(int z: path2)
                            cout << z << ' ';
                        exit(0);
                    }

                    dist[i][j] = dist[x][y] + 1;
                    q.push({i, j});
                    trace1[i] = x;
                    trace2[j] = y;
                }
            }
        }
    }

    cout << -1;
}