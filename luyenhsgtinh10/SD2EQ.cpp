#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll f1[N], f2[N], n, a[N], s1[N], s2[N], gm1[N], gm2[N];
void solve(){
  s1[0] = 0; gm1[0] = 0;
  for(int i = 1; i <= n; i++){
    s1[i] = s1[i-1] + a[i];
    gm1[i] = min(gm1[i-1], s1[i]);
    f1[i] = max(s1[i] - gm1[i], f1[i-1]);
  }
  s2[n+1] = 0; gm2[n+1] = 0;
  for(int i = n; i >= 1; i--){
    s2[i] = s2[i+1] + a[i];
    if(s2[i] < gm2[i+1])
        gm2[i] = s2[i];
    else
        gm2[i] = gm2[i+1];
    f2[i] = max(s2[i] - gm2[i], f2[i+1]);
  }
  ll ans = LLONG_MIN;
  for(int i = n; i >= 1; i--)
    ans = max(ans, f1[i-1] +  f2[i]);
    cout<<ans;
} 
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("SD2EQ.inp","r",stdin);
    freopen("SD2EQ.out","w",stdout);
    cin>>n; ll kt = 0;
    for(int i = 1; i <= n; i++){
      cin>>a[i];
        if(a[i] > 0)
            kt = 1;
    }
    if(kt == 0){
        sort(a+1, a+1+n);
        cout<<a[n]+a[n-1];
        return 0;
    }
    solve();
}