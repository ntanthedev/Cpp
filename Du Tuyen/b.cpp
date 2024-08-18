#include<bits/stdc++.h>
#define ll long long
const int N = 1e5+9;
using namespace std;
ll n, m = 1, gmax = 0;
ll f[N], a[N];
void solve(){
    //memset(f, INT_MAX, sizeof(f));
    f[0] = INT_MIN;
    f[1] = a[1];
    for(int i = 2; i <= n; i++){
        if(f[1] > a[i])
            f[1] = a[i];
        if(a[i] > f[m]){
            f[++m] = a[i];
        }
        else{
            ll t = upper_bound(f, f+m, a[i]) - f - 1;
            if(f[t] != a[i])
                t++;
            f[t] = a[i];
        }
    }
    //for(int i = 1; i <= m; i++)
      //  cout<<f[i]<<" ";
    cout<<m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("test.inp","r",stdin);
    freopen("B.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    solve();
}
