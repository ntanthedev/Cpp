//problem "MECUNG4"
//created in 19:13:53 - Tue 03/12/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

template<typename T> using vt = vector<T>;
typedef pair<int, int> ii;

int dx[] = {1, -1, 0, 0}, 
    dy[] = {0, 0, 1, -1};

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "MECUNG4"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, m;

    cin >> m >> n;

    vt<vt<int>> w(m + 1, vt<int>(n + 1)), dis(m + 1, vt<int>(n + 1, LLONG_MAX));
    vt<vt<bool>> vis(m + 1, vt<bool>(n + 1, false));    

    for(int i = 1, u, v; i <= m; i++) 
        for(int j = 1; j <= n; j++) {
            cin >> w[i][j];
        }

    deque<ii> q;

    for(int i = 1; i <= m; i++) {
        q.push_back({i, 1});
        dis[i][1] = 1;
    }

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();

        if(vis[x][y])
            continue;
        vis[x][y] = true;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i],
                ny = y + dy[i];

            if(nx < 1 || nx > m || ny < 1 || ny > n || dis[x][y] + (w[x][y] != w[nx][ny]) > dis[nx][ny])
                continue;
            
            if(w[nx][ny] != w[x][y]) 
                q.push_back({nx, ny});
            else 
                q.push_front({nx, ny});
            dis[nx][ny] = min(dis[nx][ny], dis[x][y] + (w[x][y] != w[nx][ny]));
        }
    }

    // cout << '\n';
    // for(int i = 1; i <= m; cout << '\n', i++) 
    //     for(int j = 1; j <= n; j++) 
    //         cout << dis[i][j] << " ";

    int ans = LLONG_MAX;

    for(int i = 1; i <= m; i++) 
        ans = min(ans, dis[i][n]);

    cout << ans;
}