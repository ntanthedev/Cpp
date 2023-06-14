#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e5+9;
ll dp[N][3], n, a, b, c, v[3];
void solve(){
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++){
        cin>>v[0]>>v[1]>>v[2];
        for(int j = 0; j <= 2; j++){
            for(int k = 0; k <= 2; k++){
                if(k != j)
                    dp[i][j] = max(dp[i-1][k] + v[j], dp[i][j]); 
            }
        }
    }
    cout<<max(dp[n][0], max(dp[n][1], dp[n][2]));
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    solve();
}