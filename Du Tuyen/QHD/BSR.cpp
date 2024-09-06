//problem "BSR"
//created in 21:24:36 - Sun 21/04/2024

#include<bits/stdc++.h>

#define int int64_t
const int N = 5e2 + 2;

using namespace std;

int m, n;
int a[N][N], f[N][N], d[N][N][9];

int sum(int x1, int y1, int x2, int y2) {
    return f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> m >> n;
    
    for(int i = 1; i <= m; i++) 
        for(int j = 1; j <= n; j++) 
            cin >> a[i][j], 
            f[i][j] = a[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
    
    for(int i = 0; i <= m; i++) f[i][0] = 0;
    for(int j = 0; j <= n; j++) f[0][j] = 0;
    
    int ans = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {

        }
    }
    cout << ans;
}