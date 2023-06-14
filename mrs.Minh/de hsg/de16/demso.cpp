#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll a[N], n, Q, k;
void solve(){
    cin>>k;
    ll t = lower_bound(a+1, a+1+n, k) - a, v = upper_bound(a+1, a+1+n, k) - a;
    cout<<n - v + 1<<" "<<t - 1<<'\n';
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("demso.inp","r",stdin);
    freopen("demso.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1, a+1+n);
    cin>>Q;
    while (Q--)
        solve();
}