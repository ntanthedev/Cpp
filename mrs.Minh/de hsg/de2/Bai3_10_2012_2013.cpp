#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, d = 0, x;
map<ll, ll>M;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai3_10_2012_2013.inp","r",stdin);
    freopen("Bai3_10_2012_2013.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>x;
        M[x]++;
    }
    for(auto i : M){
        ll f = i.first, s = i.second;
        d += s/f;
    }
    cout<<d;
}