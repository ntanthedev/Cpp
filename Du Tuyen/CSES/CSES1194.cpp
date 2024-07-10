//problem "CSES1194"
//created in 20:00:07 - Tue 09/07/2024

#include<bits/stdc++.h>

#define int int64_t
#define fi first 
#define se second

using namespace std;

int dx[] = {1, -1, 0, 0},
    dy[] = {0, 0, 1, -1};

void bfs(int m, int n, pair<int, int> x, vector<vector<char>> &a, vector<vector<int>> &d, vector<vector<pair<int, int>>> &trace) {
    queue<pair<int, int>> q;
    q.push({x});
    d[x.fi][x.se] = 0;
    
    while(!q.empty()) {
        pair<int, int> u = q.front(); q.pop();

        for(int i = 0; i < 4; ++i) {
            int nx = u.fi + dx[i],
                ny = u.se + dy[i];
            if(nx < 1 || nx > m || ny < 1 || ny > n || a[nx][ny] == '#' || d[nx][ny] <= d[u.fi][u.se] + 1)
                continue;
            d[nx][ny] = d[u.fi][u.se] + 1;
            trace[nx][ny] = {u.fi, u.se};
            q.push({nx, ny});
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int m, n;
    cin >> m >> n;
    vector<vector<char>> a(m + 1, vector<char>(n + 1));
    pair<int, int> start;
    vector<pair<int, int>> monster;
    vector<vector<int>> b(m + 1, vector<int>(n + 1, LLONG_MAX)), c(m + 1, vector<int>(n + 1, LLONG_MAX));
    vector<vector<pair<int, int>>> tc(m + 1, vector<pair<int, int>>(n + 1, {-1, -1})), tb(m + 1, vector<pair<int, int>>(n + 1, {-1, -1}));

    for(int i = 1; i <= m; i++) 
        for(int j = 1; j <= n; j++) { 
            cin >> a[i][j];
            if(a[i][j] == 'A')
                start = {i, j};
            if(a[i][j] == 'M')
                monster.push_back({i, j});
        }
    
    for(auto i : monster) {
        bfs(m, n, i, a, b, tb);
    }

    bfs(m, n, start, a, c, tc);

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j != n; j = n)
            if(a[i][j] != '#' && (b[i][j] > c[i][j])) {

            }
    }
}