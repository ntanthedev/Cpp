#include<bits/stdc++.h>
#define ll long long
#define xau "reward"
const int N = 1e6+9;
using namespace std;
ll dp[N], a[N], n, k;
void solve(){
    if(k==1){
        dp[0] = 0;
        dp[1] = a[1];
        dp[2] = max(a[1], a[2]);
        for(int i = 2; i <= n; i++)
            dp[i] = max(dp[i-1], dp[i-2] + a[i]);
    }
    else{
        dp[0] = 0;
        dp[1] = a[1];
        dp[2] = a[2];
        for(int i = 2; i <= n; i++){
            dp[i] = max(dp[i-1], max(dp[i-2] + a[i], dp[i-3] + a[i-1] + a[i]));
        }
    }
    cout<<dp[n];
//    for(int i = 1; i <= n; i++)
//        cout<<dp[i]<<" ";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(xau".inp","r")){
        freopen(xau".inp","r",stdin);
        freopen(xau".out","w",stdout);
    }
    else{
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < 0)
            a[i] = 0;
    }
    cin >> k;
    solve();
}


