#include<bits/stdc++.h>
#define ll long long
#define xau "a"
#define fi first
#define se second
#define ii pair<int, int>
const int N = 1e6+9;
using namespace std;
ll t, f[N];
ii a[N];
bool cmp(ii a, ii b){
    return a.fi < b.fi || (a.fi == b.fi && a.se > b.se);
}
void solve(){

    ll n, m = 1;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a+1, a+1+n, cmp);
    //for(int i = 1; i <= n; i++) cout<<a[i].fi<<" "<<a[i].se<<"||";
    f[1] = a[n].se;
    for(int i = n-1; i >= 1; i--){
        if(a[i].se >= f[m])
            f[++m] = a[i].se;
        else if(a[i].se < f[1])
            f[1] = a[i].se;
        else{
            ll t = upper_bound(f+1, f+m+1, a[i].se) - f;
            f[t] = a[i].se;
        }
    }
    //cout<<'\n';
    cout<<m<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
     if(fopen(xau".inp","r")){
         freopen(xau".inp","r",stdin);
         freopen(xau".out","w",stdout);
     }
    cin >> t;
    while(t--)
        solve();
}
