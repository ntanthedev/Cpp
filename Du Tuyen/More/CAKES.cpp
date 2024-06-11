//problem "CAKES"
//created in 09:08:28 - Sun 12/05/2024

#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")

#define int int64_t
#define fi first 
#define se second

using namespace std;

int n, S;

void sub2() {
    vector<pair<int, pair<int, int>>> a(1);
    for(int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        if(!a.empty() && x == a.back().fi)
            a.back().se.fi += y, a.back().se.se++;
        else 
            a.push_back({x, {y, 1}});
    }

    n = a.size() - 1;

    vector<vector<int>> dp(n + 2, vector<int>(S + 2));

    dp[0].resize(S + 2, 0);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= S; j++) {
            if(j >= a[i].fi + a[i].se.fi) 
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].fi + a[i].se.fi] + a[i].se.se);
            else 
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][S];
}   

void sub3() {

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #define task "CAKES"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> S;
    if(n * S <= 1e7)
        sub2();
}