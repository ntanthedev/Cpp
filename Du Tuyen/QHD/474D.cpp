//problem "474D"
//created in 12:56:49 - Fri 09/08/2024

#include<bits/stdc++.h>

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

using namespace std;

long long dp[N], k, t;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t >> k;

    for(int i = 0; i < k; i++) 
        dp[i] = 1;

    for(int i = k; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
    }

    // for(int i = 1; i <= 10; i++) 
    //     cout << i << ": " << dp[i] << '\n';

    for(int i = 1; i <= N; i++) {
        dp[i] += dp[i - 1];
        dp[i] %= MOD;
    }

    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << (dp[b] - dp[a - 1] + MOD) % MOD << '\n';
    }
}   

/*
R
RR, WW 
RRR, RWW, WWR
RRRR, RRWW, RWWR, WWRR, WWWW
RRRRR, RRRWW, RRWWR, RWWRR, WWRRR, RWWWW, WWRWW, WWWWR

----

R 
RR 
RRR, WWW 
RRRR, RWWW, WWWR
RRRRR, RRWWW, RWWWR, WWWRR
RRRRRR, RRRWWW, RRWWWR, RWWWRR, WWWRRR, WWWWWW

dp[i] = dp[i - 1] + (dp[i - 1] - 1) + (i % k == 0)
*/