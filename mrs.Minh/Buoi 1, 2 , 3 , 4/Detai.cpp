#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, j, res;
map<ll, ll>M;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("detai.inp","r",stdin);
    freopen("detai.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>j;
        M[j]++;
    }
    for(auto i: M){
        ll x = i.first, y = i.second, z;
        z = y/x;
        res += z;
    }
    cout<<res;
}