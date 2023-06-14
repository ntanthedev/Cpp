#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, a, dem;
map<ll, ll>M;
void slove(){
    for(auto i: M){
        ll t = i.second - 1;
        dem += (t+1)*t/2;
    }
    cout<<dem;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("CAPDOI.inp","r",stdin);
    freopen("CAPDOI.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a;
        M[a]++;
    }
    slove();
}