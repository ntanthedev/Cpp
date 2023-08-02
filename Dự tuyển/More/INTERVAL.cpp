#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll n;
struct pt{
    ll x, y, vt;
};
pt b[N], a[N];
bool cmp(pt c, pt d){
    return c.y < d.y;
}
void solve(){
    sort(a+1, a+1+n, cmp);
    sort(b+1, b+1+n, cmp);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += abs(a[i].y - b[i].y);
    }
    cout<<ans<<'\n';
    for(int i = 1; i <= n; i++)
        cout<<b[i].vt<<" "<<a[i].vt<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("INTERVAL.inp","r",stdin);
    freopen("INTERVAL.out","w",stdout);
    cin>>n; char kt; ll l = 0, r = 0;
    for(int i = 1; i <= 2*n; i++){
        cin >> kt;
        if(kt == 'W'){
            a[++l].x = 1;
            cin>>a[l].y;
            a[l].vt = i;
        }
        else{
            b[++r].x = 2;
            cin>>b[r].y;
            b[r].vt = i;
        }
    }
    solve();
}

