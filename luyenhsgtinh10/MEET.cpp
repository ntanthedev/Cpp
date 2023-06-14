#include<bits/stdc++.h>
#define tag "MEET"
#define ll long long 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
using namespace std;
ll n, Q, a[N], b[N], x, y;

void solve(){
    cin >> x >> y;
    ll m, t = b[x] + b[y];
    m = lower_bound(a+1, a+1+n, t) - a;
    
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a+1, a+1+n);
    while(Q--)
        solve();
}