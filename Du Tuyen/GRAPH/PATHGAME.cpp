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
    
    #define task "PATHGAME"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, m, Q;

    cin >> m >> n >> Q;

    vector<vector<char>> a(m + 1, vector<char> (n + 1));
    vector<vector<int>> b(m + 1, vector<int> (n + 1, -1));
    priority_queue<pair<int, ii>, vector<pair<int, ii>>> q;

    for(int i = 1; i <= m; i++) 
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] == '*') {
                b[i][j] =  0;
                q.push(mp(0LL, mp(i, j)));
            }
        }
    
    while(!q.empty()) {
        auto d = q.top().first;
        auto [x, y] = q.top().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i],
                ny = y + dy[i];
            if(nx < 1 || nx > m || ny < 1 || ny > n || b[nx][ny] != -1)
                continue;
            b[nx][ny] = b[x][y] + (a[nx][ny] != a[x][y]);
            q.push(mp(b[nx][ny], mp(nx, ny)));
        }
    }

    while(Q--) {
        int x, y;
        cin >> x >> y;
        cout << b[x][y] << '\n';
    }
}