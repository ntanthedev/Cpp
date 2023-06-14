#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, ans = 0;
ll giaithua(ll x){
    if(x == 1)
        return 1;
    return x * giaithua(x - 1);
}
void solve(){
    for(int i = 1; i <= n; i++){
        ans += giaithua(i);
    }
    cout<<ans;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("bai1_10_2015_2016.inp","r",stdin);
    freopen("bai1_10_2015_2016.out","w",stdout);
    cin>>n;
    solve();
}