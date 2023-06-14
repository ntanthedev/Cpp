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
            ll t = lower_bound(f+1, f+1+m, a[i]) - f;
            f[t] = a[i];
        }
    }
    cout<<m<<'\n';
    // for(int i = 1; i <= m; i++)
    //     cout<<f[i]<<" ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen("lis.inp", "r")){
        freopen("lis.inp","r",stdin);
        freopen("lis.out","w",stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    solve();
}
