#include<bits/stdc++.h>
#define tag "CHIANHOM"
#define ll long long
#define ii pair<ll, ll> 
const int N = 1e6+9;
using namespace std;
ll n, ans = 0;
ii x;
map<ii, bool> M;
void solve(){
    for(int i = 1; i <= n; i++){
        cin >> x.first >> x.second;
        if(!M[x])
            ans++;
        M[x] = true;
    }
    cout<<ans;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n;
    solve();
}