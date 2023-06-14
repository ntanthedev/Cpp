#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll a[N], n, k, sum = 0;
bool check(ll x){
    ll d = 0;
    for(int i = 1; i <= n; i++){
        d = d + a[i]/x;
        if(d >= k)
            return 1;
    }
    
        return 0;
}
void solve(){
    ll res, m = sum/k;
    ll mid,L =1, R = m+1;
    while (L <= R)
    {
        /* code */
        mid = (L + R)/2;
        if(check(mid)){
            res = mid;
            L = mid+1;
        }
        else
            R = mid-1;
    }
    cout<<res;
    
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("game.inp","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        sum += a[i];
    }
    solve();
}