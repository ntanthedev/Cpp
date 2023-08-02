#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
const int N = 1e6+9;
using namespace std;
pair<int, int>a[110];
ll n, res = 0, ans = 0;
void solve(){
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        res = res - a[i].fi + a[i].se;
        ans = max(res, ans);
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("ATRAIN.inp","r",stdin);
    //freopen("ATRAIN.out","w",stdout);
    cin >> n;
    solve();
}
