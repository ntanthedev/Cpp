#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n;
ll tichso(ll x){
    ll res = 1;
    while(x != 0){
        res *= x%10;
        x /= 10;
    }
    return res;
}
void dequy(ll x){   
    if(x < 10)
        cout<<x;
    else
        dequy(tichso(x));
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai1_10_thithu11.inp","r",stdin);
    freopen("Bai1_10_thithu11.out","w",stdout);
    cin>>n;
    dequy(n);
}