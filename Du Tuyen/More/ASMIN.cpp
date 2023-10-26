#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define xau "ASMIN"
#define ii pair<int, int>
const int N = 1e6+9;
using namespace std;
ll m, n, gmin = 99999999;
ii ans, a[N], b[N];

inline void Update(int i, int j){
    if(abs(a[i].fi + b[j].fi) < gmin){
        gmin = abs(a[i].fi + b[j].fi);
        ans.fi = a[i].se;
        ans.se = b[j].se;
    }
}
void solve(){
    sort(a+1, a+1+m);
    sort(b+1, b+1+n);
    ll l, r;
    ii temp;
    for(int i = 1; i <= m; i++){
        temp.fi = (-1)*a[i].fi;
        temp.se = (-1)*a[i].se;
        if(a[i].fi <= b[1].fi){
            Update(i, 1);
            Update(i, n);
        }
        else if(a[i].fi >= b[n].fi){
            Update(i, n);
            Update(i, 1);
        }
        else{
            l = lower_bound(b+1, b+1+n, ii(a[i].fi, 0)) - b;
            //r = lower_bound(b+1, b+1+n, ii(temp.fi, 0)) - b;
            Update(i, l);
            Update(i, l-1);
            //Update(i, r);
            //Update(i, r-1);
        }
        if(temp.fi <= b[1].fi){
            Update(i, 1);
            Update(i, n);
        }
        else if(temp.fi >= b[n].fi){
            Update(i, n);
            Update(i, 1);
        }
        else{
            //l = lower_bound(b+1, b+1+n, ii(a[i].fi, 0)) - b;
            r = lower_bound(b+1, b+1+n, ii(temp.fi, 0)) - b;
            //Update(i, l);
            //Update(i, l-1);
            Update(i, r);
            Update(i, r-1);
        }
    }
    cout<<ans.fi<<" "<<ans.se;
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
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i].first;
        b[i].second = i;
    }
    solve();
}
