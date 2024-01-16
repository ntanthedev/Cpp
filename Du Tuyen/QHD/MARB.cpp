#include <bits/stdc++.h>

#define int long long
using namespace std;

int dp[201][201][201];

int f(int t, int b, int c) {
    if(t<0)return 0;
    if(t==0)return 1;
    if(b==0)return 0;
    if(c==0)return 0;
    if(dp[t][b][c] != -1) return dp[t][b][c];
    dp[t][b][c] = 0;
    for(int i = 0; i <= c; ++i)
        dp[t][b][c] += f(t-i,b-1,i);
    return dp[t][b][c];
}

void solve() {
    //initialize
    int n,m,k;
    cin >> n >> m >> k;
    
    //solve
    memset(dp,-1,sizeof(dp));
    int t = 0;
    // for(int i = 0; i <= k; f(n,m,i);
    cout << f(n,m,k);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("marb.inp","r",stdin);
    freopen("marb.out","w",stdout);
    
    solve();
}