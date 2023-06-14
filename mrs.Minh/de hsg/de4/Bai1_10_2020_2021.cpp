#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
bool check(ll n){
    if(n%2 == 0)
        return false;
    for(int i = 3; i <= sqrt(n); i += 2){
        if(n%i == 0)
            return false;
    }
    return true;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai1_10_2020_2021.inp","r",stdin);
    freopen("Bai1_10_2020_2021.out","w",stdout);
    ll n, m;
    cin>>n;
    m = sqrt(n);
    while(true){
        if(check(m) == true)
            break;
        m++;
    }
    cout<<m*m;
}