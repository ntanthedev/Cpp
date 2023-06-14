#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll T, l, r;

void sub1(){
    ll d4, d7, d11;
    d4 = r/4 - l/4;
    if(l%4 == 0)
        d4++;
    d7 = r/7 - l/7;
    if(l%7 == 0)
        d7++;
    d11 = r/11 - l/11;
    if(d11%11 == 0)
        d11++;
    ll bcnn = 308;
    ll dbc = r/bcnn - l/bcnn;
    if(l%bcnn == 0)
        dbc++;
    ll d1, d2, d3;
    d1 = r/28 - l/28;
    if(l%28 == 0)
        d1++;
    d2 = r/77 - l/77;
    if(l%77 == 0)
        d2++;
    d3 = r/44 - l/44;
    if(l%44 == 0)
        d3++;
    ll ans;
    ans = d4 + d7 + d11 + d1 + d2 + d3 - dbc;
    cout<<ans<<'\n';
}

void sub2(){
    ll dem = 0;
    for(int i = l; i <= r; i++){
        if(i%4 == 0 || i%7 == 0 || i%11 == 0)
            dem++;
    }
    cout<<dem<<'\n';
}
void solve(){
    if(r <= 1e6)
        sub1();
    else
        sub1();
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("DIVISIBLE.inp","r",stdin);
    freopen("DIVISIBLE.out","w",stdout);
    cin>>T;
    for(int t = 1; t <= T; t++){
        cin>>l>>r;
        solve();
    }
}