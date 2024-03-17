#include<bits/stdc++.h>

#define int int64_t
const int N = 1e6 + 9;

using namespace std;

int n, mod, dp[N];

void sub2() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = dp[1] + dp[2] + 1;
    for(int i = 4; i <= n; i++) 
        dp[i] = (dp[i-1]%mod + dp[i-2]%mod + dp[i-3]%mod)%mod;
    for(int i = 1; i <= n; i++)
        cout << dp[i] << " " ;
    cout << dp[n];
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "CMOVE"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> mod;
    if(n <= 1e6)
        sub2();
}