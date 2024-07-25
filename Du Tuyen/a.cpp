//problem "a"
//created in 16:42:29 - Thu 25/07/2024

#include<bits/stdc++.h>

// #define int long long
const int N = 18;

using namespace std;

int n;
int d[N][N], dp[(1 << N)][N];

struct pt {
    int x, y, z;

    int dis(pt a) {
        return abs(x - a.x) + abs(y - a.y) + max(0, a.z - z);
    }

} a[N];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            d[i][j] = (i != j ? 1e9 : 0);

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            for(int k = 1; k <= n; k++) 
                d[j][k] = min(d[j][k], d[j][i] + a[i].dis(a[k]));
    
    for(int i = 0; i < (1 << n); ++i) {
        for(int j = 0; j < n; ++j) {
            dp[i][j] = 1e9;
        }
    }

    dp[1][0] = 0;

    for(int i = 1; i < (1 << n); ++i) {
        for(int j = 0; j < n; ++j) {
            if(i >> j & 1) {
                for(int k = 0; k < n; ++k) {
                    if(!(i >> k & 1)) {
                        dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + d[j + 1][k + 1]); 
                    }
                }
            }
        }
    }

    int ans = 1e9;

    for(int i = 0; i < n; ++i) {
        ans = min(ans, dp[(1 << n) - 1][i] + d[i + 1][1]);
    }

    cout << ans;
}