#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, a[N];
void sub1(){
    ll uc;
    cin>>a[1]>>a[2];
    uc = __gcd(a[1], a[2]);
    for(int i = 2; i <= n; i++){
        cin>>a[i];
        uc = __gcd(uc, a[i]);
    }

}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("game.inp","r",stdin);
    // freopen("game.out","w",stdout);
    cin>>n;
    if(n <= 1e6)
        sub1();
    //solve();
}
