//problem "PATHGAME"
//created in 07:20:22 - Tue 03/12/2024

#include<bits/stdc++.h>

#define int int64_t
#define mp make_pair 

using namespace std;

typedef pair<int, int> ii;

int dx[] = {1, -1, 0, 0},
    dy[] = {0, 0, 1, -1};

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "MECUNG3"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, m, Q, bx, by;

    cin >> m >> n >> Q >> bx >> by;

    vector<vector<char>> a(m + 1, vector<char> (n + 1));
    vector<vector<int>> b(m + 1, vector<int> (n + 1, LLONG_MAX));
    vector<vector<bool>> vis(m + 1, vector<bool> (n + 1, false));
    deque<pair<int, ii>> dq;

    for(int i = 1; i <= m; i++) 
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }

    // int tt = 0;
    // vector<vector<int>> time(m + 1, vector<int> (n + 1, 0));
    
    dq.push_back(mp(0, mp(bx, by)));
    b[bx][by] = 0;

    while(!dq.empty()) {
        auto d = dq.front().first;
        auto [x, y] = dq.front().second;
        dq.pop_front();

        if(vis[x][y]) 
            continue;
        vis[x][y] = true;
        // time[x][y] = ++tt;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i],
                ny = y + dy[i];
            if(nx < 1 || nx > m || ny < 1 || ny > n || vis[nx][ny])
                continue;
            if(a[nx][ny] != a[x][y]) {
                b[nx][ny] = min(b[nx][ny], b[x][y] + 1);
                dq.push_back(mp(1, mp(nx, ny)));
            }
            else {
                b[nx][ny] = min(b[nx][ny], b[x][y]);
                dq.push_front(mp(0, mp(nx, ny)));
            }
        }
    }

    // for(int i = 1; i <= m; cout << '\n', i++) 
    //     for(int j = 1; j <= n; j++) 
    //         cout << b[i][j];
    
    // for(int i = 1; i <= m; cout << '\n', i++) 
    //     for(int j = 1; j <= n; j++) 
    //         cout << time[i][j] << " ";

    while(Q--) {
        int x, y;
        cin >> x >> y;
        cout << b[x][y] << '\n';
    }
}