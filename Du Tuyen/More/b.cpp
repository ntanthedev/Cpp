#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second 
typedef long long ll;
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>dp(n+1,vector<ll>(m+1));
    dp[1][1]=2;dp[1][2]=4,dp[2][1]=2,dp[2][2]=16;
    for(ll i=1;i<=n;i++)
    {
        
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}