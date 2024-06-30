//template simple for codeforces by ntannn_
//created in 02:32:23 - Sun 30/06/2024
#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int dy[] = {0, 0, 1, -1},
    dx[] = {1, -1, 0, 0};

void solve() {
    int n, m;
    pair<int, int> st;
    map<pair<int, int>, bool> check;
    cin >> m >> n;
    vector<vector<char>> a(m + 1, vector<char>(n + 1));
    vector<vector<int>> dem(m + 1, vector<int>(n + 1));

    for(int i = 1; i <= m; i++) 
        for(int j = 1; j <= n; j++) { 
            cin >> a[i][j];
            if(a[i][j] == 'L')
                st = {i, j};
        }

    queue<pair<int, int>> q;
    q.push({st});
    check[st] = 1;

    while(!q.empty()) {
        auto u = q.front(); q.pop();

        int cnt = 0;
        for(int i = 0; i < 4; i++) {
            int nx = u.first + dx[i], ny = u.second + dy[i];
            if(nx > m || nx < 1 || ny < 1 || ny > n)
                continue;
            if(a[nx][ny] == '.')
                cnt++;
        }

        dem[u.first][u.second] = cnt;
        if(cnt > 1 && u != st) 
            continue;
        
        if(a[u.first][u.second] != 'L')
            a[u.first][u.second] = '+';

        for(int i = 0; i < 4; i++) {
            int nx = u.first + dx[i], ny = u.second + dy[i];
            if(nx > m || nx < 1 || ny < 1 || ny > n)
                continue;
            
            if(a[nx][ny] == '.') {
                check[make_pair(nx, ny)] = 1;
                q.push({nx, ny});
            }
        }
    }

    for(int i = 1; i <= m; i++, cout << '\n') 
        for(int j = 1; j <= n; j++) 
            cout << a[i][j];
    
    // for(int i = 1; i <= m; i++, cout << '\n') 
    //     for(int j = 1; j <= n; j++) 
    //         cout << dem[i][j];
}

int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case;
    for(cin >> test_case;test_case--;) 
        solve();
}