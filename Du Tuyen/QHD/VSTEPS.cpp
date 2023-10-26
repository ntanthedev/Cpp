#include<bits/stdc++.h>
#define tag "VSTEPS"
#define ll long long 
const int N = 1e5+9;
const int mod = 14062008;
using namespace std;
ll ans = 0, dp[N], n, k, x;
unordered_map<ll, bool> M;
void solve(){
    dp[1] = 1, dp[2] = 1;
    for(int i = 3; i <= n; i++){
        if(M[i])
            dp[i] = 0;
        else{
            dp[i] = (dp[i-2]%mod + dp[i-1]%mod)%mod;
            //cout<<i<<": "<<dp[i]<<'\n';
        }
    }
    cout<<dp[n];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        cin >> x;
        if(M[x-1]){
            cout<<0;
            return 0;
        }
        M[x] = true;
    }
    solve();
}