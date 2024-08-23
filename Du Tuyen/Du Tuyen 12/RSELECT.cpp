#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")

using namespace std;

int n, a[1002][1002];
vector<int> mm;
vector<vector<pair<int, int>>> d;
int m[1000009];
int ans = 0;
bool b[1001][1001];
int dx[4] = {1, -1, 0, 0},
    dy[4] = {0, 0, 1, -1};

int check(int val) {
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) 
            b[i][j] = 0;

    int t = m[val];

    for(pair<int, int> xx : d[t]) {
        if(b[xx.first][xx.second])
            continue;
        b[xx.first][xx.second] = 1;
        queue<pair<int, int>> q;
        q.push(xx);
        while(!q.empty()) {
            cnt++;
            int x = q.front().first, y = q.front().second; q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if(b[nx][ny] || nx <= 0 || ny <= 0 || nx > n || ny > n) 
                    continue;
                
                if(abs(a[nx][ny] - a[x][y]) == val) {
                    q.push({nx, ny});
                    b[nx][ny] = 1;
                }
            }
        }
    }

    return cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define task "RSELECT"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) { 
            cin >> a[i][j];
            if(i != 1) 
                mm.push_back(abs(a[i][j] - a[i - 1][j]));
            if(j != 1) 
                mm.push_back(abs(a[i][j] - a[i][j - 1]));
        }

    sort(mm.begin(), mm.end());
    mm.resize(unique(mm.begin(), mm.end()) - mm.begin());
    
    for(int i = 0; i < mm.size(); i++) {
        m[mm[i]] = i;
    }

    d.resize(mm.size(), vector<pair<int, int>>());

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) { 
            if(i != 1) 
                d[m[abs(a[i][j] - a[i - 1][j])]].push_back({i, j});
            if(j != 1) 
                d[m[abs(a[i][j] - a[i][j - 1])]].push_back({i, j});
        }    

    for(int i = 0; i < mm.size(); i++) {
        ans = max(check(mm[i]), ans);
    }


    cout << ans;
}