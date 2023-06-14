#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, a[N], b[N];
void solve(){
    sort(a+1, a+1+n);
    ll g1 = a[n-2], g2 = a[n-1], g3 = a[n];
    for(int i = 1; i <= n; i++){
        if(b[i] == g1){
            cout<<b[i]<<" ";
            g1 = -999;
        }
        if(b[i] == g2){
            cout<<b[i]<<" ";
            g2 = -999;
        }
        if(b[i] == g3){
            cout<<b[i]<<" ";
            g3 = -999;
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai3_10_2014_2015.inp","r",stdin);
    freopen("Bai3_10_2014_2015.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        b[i] = a[i];
    }
    solve();
}