#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, x, dem = 0;
void solve(){
    for(int i = 1; i <= n; i++){
        if(x%i == 0 && x/i <= n)
            dem++;
    }
    cout<<dem;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai1_10_thithu12.inp","r",stdin);
    freopen("Bai1_10_thithu12.out","w",stdout);
    cin>>n>>x;
    if(x == 0)
        cout<<0;
    else
        solve();
}