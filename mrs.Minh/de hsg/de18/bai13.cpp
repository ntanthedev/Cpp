#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, x, a[N], s[N];
unordered_map<ll, ll>M;
void solve(){
    ll res = 0;
    for(int i = 1; i <= n; i++){
        if(M[s[i] - x] != 0)
            res+= M[s[i] - x];
    }
    cout<<res;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("bai13.inp","r",stdin);
    freopen("bai13.out","w",stdout);
    cin>>n>>x; s[0] = 0;
    x = abs(x);
    M[0] = 1;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        s[i] = s[i-1]+a[i];
        M[s[i]]++;
    }
    solve();
}