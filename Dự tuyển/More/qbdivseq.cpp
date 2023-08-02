#include<bits/stdc++.h>
#define ll long long
#define xau "a"
const int N = 1e6+9;
using namespace std;
ll n, a[N], f[N], m = 1;
void solve(){
    f[1] = a[1];
    for(int i = 2; i <= n; i++){
        if(f[m] < a[i])
            f[++m] = a[i];
        if(a[i] < f[1])
            f[1] = a[i];
        else{
            ll t = lower_bound(f+1, f+1+m, a[i]) - f;
            f[t] = a[i];
        }
    }
    //for(int i = 1; i <= m; i++) cout<<f[i]<<" ";
    cout<<m;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(xau".inp","r")){
        freopen(xau".inp","r",stdin);
        freopen(xau".out","w",stdout);
    }
    cin >> n;
    for(int i = n; i >= 1; i--)
        cin >> a[i];
    solve();
}
