#include<bits/stdc++.h>
#define tag "XAUCON"
#define ll long long 
const int N = 1e6+9;
using namespace std;
ll n, s[N], k, ans = 0;
string a;
void solve(){
    for(int i = 1; i <= n; i++){
        ll t = lower_bound(s+1, s+1+n, s[i] + k) - s - 1;
        ans += n - t + 1;
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
    cin >> n >> k >> a; s[0] = 0;
    a = ' ' + a;
    for(int i = 1; i < a.size(); i++){
        s[i] = s[i-1] + a[i];
    }
    solve();
}