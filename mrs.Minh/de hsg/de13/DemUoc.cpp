#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n;
void solve(){
    ll cnt = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n%i == 0){
            cnt ++;
            if(i != n/i)
                cnt++;
        }
    }
    cout<<cnt;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("DemUoc.inp","r",stdin);
    freopen("DemUoc.out","w",stdout);
    cin>>n;
    solve();
}