#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, a[N], gmax= 0;
void solve(){
    ll d = 1;
    a[0] = -1213243434;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        gmax = max(gmax, d);
        if(a[i] == a[i-1])
            d++;
        else
            d = 1;
    }
    cout<<n - gmax;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai2_10_thithu12.inp","r",stdin);
    freopen("Bai2_10_thithu12.out","w",stdout);
    cin>>n;
    solve();
}