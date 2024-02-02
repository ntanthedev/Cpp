#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 9;

ll n, a[N], dp[N], k;

void solve() {
    dp[0] = 0;
    dp[1] = a[1];
    if(k == 1) 
        for(int i = 2; i <= n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + a[i]);        
        }
    else {
        dp[2] = a[1] + a[2];
        for(int i = 3; i <= n; i++) {
            dp[i] = max({dp[i-1], dp[i-2] + a[i-1], dp[i-3] + a[i-1] + a[i]});
        }
    }
    cout << dp[n] ;
}

signed main() {
    #define task "reward"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> k;
    solve();
}