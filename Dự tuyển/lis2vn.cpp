// code chua full
#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define xau "a"
const int N = 1e6+9;
using namespace std;
ll n, m = 1;
ii a[N], f[N];
bool cmp(ii x, ii y){
    return x.fi < y.se || (x.fi == y.fi && x.se > y.se);
}
bool sosanh(ii x, ii y){
    if(x.fi > y.fi && x.se > y.se)
        return true;
    return false;
}
void solve(){
    sort(a+1, a+1+n, cmp);
    //for(int i = 1; i <= n; i++) cout<<a[i].fi<<" "<<a[i].se<<"||";
    f[1] = a[1];
    for(int i = 2; i <= n; i++){
        if(sosanh(a[i], f[m]))
            f[++m] = a[i];
        if(sosanh(f[1], a[i]))
            f[1] = a[i];
        else{
            ll t = lower_bound(f+1, f+1+m, a[i]) - f;
            f[t] = a[i];
        }
    }
    //cout<<m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(xau".inp","r")){
        freopen(xau".inp","r",stdin);
        freopen(xau".out","w",stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    solve();
}

/*
#include<bits/stdc++.h>
#define ll long long
#define xau "a"
const int N = 1e6+9;
using namespace std;

void solve(){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(xau".inp","r")){
        freopen(xau".inp","r",stdin);
        freopen(xau".out","w",stdout);
    }

    solve();
}
*/
