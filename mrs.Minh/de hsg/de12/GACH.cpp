#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll a[N], n, cnt = 1, gmin = LLONG_MAX;

void solve(){
    sort(a+1, a+1+n);
    gmin = min(gmin, a[n]);
    ll i = n;
    while(gmin != 0 && i >= 1){
        gmin--; i--;
        gmin = min(gmin, a[i]);
        cnt++;
    }
    cout<<cnt;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("GACH.inp","r",stdin);
    freopen("GACH.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    solve();
}