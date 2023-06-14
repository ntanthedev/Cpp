#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll a, b, n, m, ans = 0;
void solve(){
    if((a*m)/(m+1) < b){
        ans += (n/(m+1)*(a*m));
        if(a>b)
            ans += (n%(m+1))*b;
        else
            ans += (n%(m+1))*a;
    }
    cout<<ans;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("NEMCHUAP.inp","r",stdin);
    freopen("NEMCHUAP.out","w",stdout);
    cin >> a >> b >> n >> m;
    solve();
}