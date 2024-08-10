//problem "TRAFAIR"
//created in 07:41:08 - Sat 10/08/2024

#include<bits/stdc++.h>

// #define int int64_t
#define fi first
#define se second
const int N = 1e3;

using namespace std;

int n, m, f[N][N], a[N][N], ans = INT_MAX;

int add(pair<int, int> x, pair<int, int> y) {
    return f[y.fi][y.se] + (a[x.fi][x.se] != a[y.fi][y.se]);
}
    
int cal(int i, int j) {
    if(j == 1) {
        return 1;
    }

    if(f[i][j] != -1) 
        return f[i][j];
    
    f[i][j] = INT_MAX;

    if(i != 1) 
        f[i][j] = min(f[i][j], cal(i - 1, j) + (a[i][j] != a[i - 1][j]));
    f[i][j] = min(f[i][j], cal(i, j - 1) + (a[i][j] != a[i][j - 1]));
    if(i != m)
        f[i][j] = min(f[i][j], cal(i + 1, j) + (a[i][j] != a[i + 1][j]));
    return f[i][j];
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "TRAFAIR"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> m >> n;
    
    for(int i = 1; i <= m; i++) 
        for(int j = 1; j <= n; j++) 
            cin >> a[i][j];
    
    memset(f, -1, sizeof(f));

    for(int i = 1; i <= m; i++) {
        ans = min(ans, cal(i, n));
    }    

    cout << ans;
}

/*

*/