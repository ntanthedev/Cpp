#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll a[N], l[N], r[N], n, f[N], b[N], m = 1, ans = 0;
void solve(){
    f[1] = a[1];
    for(int i = 2; i <= n; i++){
        if(f[1] > a[i]){
            f[1] = a[i];
            l[i] = 1;
        }
        if(a[i] > f[m]){
            f[++m] = a[i];
            l[i] = m;
        }
        else{
            ll t = upper_bound(f, f+m, a[i]) - f - 1;
            if(f[t] != a[i])
                t++;
            f[t] = a[i];
            l[i] = t;
        }
    }
//    for(int i = 1; i <= n; i++)
//        cout<<l[i]<<" ";
    m = 1;
    b[1] = a[n];
    for(int i = n-1; i >= 1; i--){
        if(b[1] > a[i]){
            b[1] = a[i];
            r[i] = 1;
        }
        if(a[i] > b[m]){
            b[++m] = a[i];
            r[i] = m;
        }
        else{
            ll t = upper_bound(b, b+m, a[i]) - b - 1;
            if(b[t] != a[i])
                t++;
            b[t] = a[i];
            r[i] = t;
        }
    }
//    cout<<'\n';
//    for(int i = 1; i <= n; i++)
//        cout<<r[i]<<" ";
    ll t;
    for(int i = 1; i <= n; i++){
        t = min(l[i], r[i]);
        ans = max(ans, t*2 - 1);
    }
    ///cout<<"\nans: "<<ans;
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen("a.inp","r")){
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    solve();
}

