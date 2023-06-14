#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n;
bool b[10000009];
void sang(){
    memset(b, true, sizeof(b));
    b[0] = false;
    b[1] = false;
    for(int i = 2; i <= sqrt(10000000); i++){
        if(b[i])
            for(int j = i*i; j <= 10000000; j+=i)
                b[j] = false;
    }
}
void solve(){
    sang();
    ll ans = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(b[i])
            ans++;
    }
    cout<<ans;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("sodep.inp","r",stdin);
    freopen("sodep.out","w",stdout);
    cin>>n; 
    solve();
}