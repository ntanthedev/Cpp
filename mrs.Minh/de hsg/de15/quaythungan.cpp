#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll s, k, du;
void solve(){
    du = k - s;
    cout<<du<<'\n'<<du/5000<<" ";
    du = du%5000;
    cout<<du/2000<<" ";
    du = du%2000;
    cout<<du/1000;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("quaythungan.inp","r",stdin);
    freopen("quaythungan.out","w",stdout);
    cin>>s>>k;
    solve();
}