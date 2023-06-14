#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
unsigned ll n;
void solve(){
    cout<<n*(n+1)*(2*n + 1)/6;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("bai3_10_2015_2016.inp","r",stdin);
    freopen("bai3_10_2015_2016.out","w",stdout);
    cin>>n;
    solve();
}