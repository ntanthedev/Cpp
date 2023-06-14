#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long N = 1e6+9;
ll a[N], n, x, MOD, b[N];

void solve(){
    b[0] = 1;
    ll res = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        b[i] = (x%MOD * b[i-1])%MOD;
        res += (a[i]%MOD * b[i])%MOD;         
    }
    cout<<res%MOD;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("exp.inp","r",stdin);
    //freopen("exp.out","w",stdout);
    cin>>n>>MOD>>x;
    solve();
}