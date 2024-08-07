//problem "a"
//created in 10:23:49 - Tue 06/08/2024

#include<bits/stdc++.h>

#define int int64_t
const int MOD = 1e9 + 7;

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> dp(n + 1);
    vector<int> b(n + 1);

    for(int i = 1; i <= n; i++) 
        cin >> b[i];

    dp[1] = 1;
    int f = b[1];
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(__gcd(j, f) == b[i]) 
                dp[i] += dp[i - 1];
            dp[i] %= MOD;
        }
        f = __gcd(b[i], f);
    }
}