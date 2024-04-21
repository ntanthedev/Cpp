//problem "BSR"
//created in 21:24:36 - Sun 21/04/2024

#include<bits/stdc++.h>

#define int int64_t
const int N = 1e2 + 2;

using namespace std;

int m, n;
int a[N][N], f[N][N];
int cnt[9];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> m >> n;
    
    for(int i = 1; i <= m; i++) 
        for(int j = 1; j <= n; j++) 
            cin >> a[i][j], 
            f[i][j] = a[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++)
            cout << f[i][j] << " ";
        cout << '\n';
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            f[i][j] = a[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1]; 
            f[i][j] += 9;
            f[i][j] %= 9;
            cout << f[i][j] << " ";
        }
        cout << '\n';
    }

    
}