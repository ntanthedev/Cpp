#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll f[70], n, x;
unordered_map<ll, bool>M;
void solve(){
    ll dem = 0;
    for(int i = 1; i <= n; i++){
        cin>>x;
        if(M[x])
            dem++;
    }
    cout<<dem;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai1_10_2014_2015.inp","r",stdin);
    freopen("Bai1_10_2014_2015.out","w",stdout);
    cin>>n;
    f[1] = f[2] = 1;
    for(int i = 3; i <= 60; i++){
        f[i] = f[i-1] + f[i-2];
        M[f[i]] = true;
    }
    solve();
}