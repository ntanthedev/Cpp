#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll gmax = -999999, res = -9999999, a[N], g1[N], g2[N],s1[N], s2[N], f1[N], f2[N], n;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //freopen("SD2EQ.inp","r",stdin);
  //freopen("SD2EQ.out","w",stdout);
  cin>>n;// s1[0] = 0;
  for(int i = 1; i <= n; i++){
    cin>>a[i];
    //s1[i] = s1[i-1] + a[i];
    //gm1[i] = min(gm1[i-1], s[i]);
    res = max(res+a[i], a[i]);
    gmax = max(gmax, res);
    f1[i] = gmax;
  }
  gmax = -999999, res = -9999999;
  for(int i = 1; i <= n; i++){
    g1[i] = max(g1[i-1], f1[i]);
  }
  s2[n] = n;
  for(int i = n; i >= 1; i--){
    //s2[i] = s2[i+1] + a[i];
    res = max(res+a[i], a[i]);
    gmax = max(gmax, res);
    f2[i] = gmax;
  }
  for(int i = n; i >= 1; i--)
    g2[i] = max(g2[i+1], f2[i]);
  ll tong[N], ans = -9999999;
  for(int i = 1; i <= n; i++){
    tong[i] = f1[i] + f2[i];
    ans = max(tong[i], ans);
  }
  cout<<ans;
}
