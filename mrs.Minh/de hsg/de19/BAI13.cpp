#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll a[N], n, X, res = 0, s[N];
map<ll, ll>M;
void solve(){
    for(int i = 0; i <= n; i++){
        res += M[s[i]];
        M[s[i] + X]++;
    }
    cout<<res;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("BAI13.inp","r",stdin);
    freopen("BAI13.out","w",stdout);
    cin>>n>>X; s[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        s[i] = s[i-1] + a[i];
        //M[s[i]]++;
    }
    solve();
}