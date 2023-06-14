#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll luythua(ll n){
    if(n == 1)
        return 1;
    return n*luythua(n-1);
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai1_10_2015_2016.inp","r",stdin);
    freopen("Bai1_10_2015_2016.out","w",stdout);
    ll s = 0, n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        s += luythua(i);
    }
    cout<<s;
}