#include<bits/stdc++.h>
#define ll long long
#define xau "FD"
#define ii pair<int, int>
#define fi first
#define se second
const int N = 1e6+9;
using namespace std;
ll n, ans = 0, smin[N];
ll a[N], p[N];
void solve(){
    for(int i = 1; i <= n; i++){
        ans += smin[i] * a[i];
    }
    cout<<ans;
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
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    smin[0] = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        smin[i] = min(smin[i-1], p[i]);
    }
    solve();
}
