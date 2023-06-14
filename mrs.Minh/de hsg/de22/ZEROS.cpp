#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
unsigned ll a, b, bcnn, ucln;
void solve(){
    ucln = __gcd(a, a+1);
    bcnn = a*(a+1)/ucln;
    ll ans = 0;
    for(unsigned ll i = a+2; i <= b; i++){
        ucln = __gcd(i, bcnn);
        bcnn = bcnn*i/ucln;
        
    }
    while(bcnn%10 == 0){
            ans++;
            bcnn /= 10;
    }
    cout<<ans;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("ZEROS.inp","r",stdin);
    freopen("ZEROS.out","w",stdout);
    cin>>a>>b;
    solve();
}