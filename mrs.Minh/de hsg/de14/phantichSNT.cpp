#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;

void solve(){

}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("phantichSNT.inp","r",stdin);
    freopen("phantichSNT.out","w",stdout);
    ll n, i = 2;
    cin>>n;
    while (n%2 == 0/* condition */)
    {
        /* code */
        n /= 2;
        cout<<2<<" ";
    }
    
    for(int i = 3; i <= n; i += 2){
        while(n%i == 0){
            cout<<i<<" ";
            n /= i;
        }
    }
        
    //solve();
}