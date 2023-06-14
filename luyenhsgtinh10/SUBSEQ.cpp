#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll a[N], ans,n, s[N], gmin[N], k;
void solve(){
    ans = LLONG_MIN;
    for(int i = k; i <= n; i++){
        ans = max(ans, s[i] - gmin[i]);
    }
    cout<<ans;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("SUBSEQ.inp","r",stdin);
    freopen("SUBSEQ.out","w",stdout);
    cin>>n>>k; 
    s[0] = 0; gmin[0] = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1] + a[i];
        gmin[i] = min(gmin[i-1], s[i]);
    }
    solve();
}