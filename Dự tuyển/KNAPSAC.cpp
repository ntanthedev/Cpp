#include<bits/stdc++.h>
#define tag "KNAPSAC"
#define ii pair<int, int>
#define fi first 
#define se second
#define ll long long 
const int N = 1e2+9;
using namespace std;
ll n, W, f[N], gmax = 0;
ii a[N];
void check(){
    ll s1 = 0, s2 = 0;
    for(int i = 1; i <= n; i++){
        s1 += a[i].fi*f[i];
        if(f[i])
            s2 += a[i].se;
    }
    if(s1 < W)
        gmax = max(s2, gmax);
}
void solve(int x){
    for(int i = 0; i <= 1; i++){
        f[x] = i;
        if(x == n)
            check();
        else
            solve(x+1);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> W;
    for(int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    solve(1);
    cout<<gmax;
}