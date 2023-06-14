#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll a[N], n, ans = 0;
    ll x = 0;
map<ll, ll>M;
ll b[N];
void solve(){
    sort(b+1, b+1+x);
    for(int i = 1; i <= x; i++){
        if(M[b[i]] >= 2){
            ll chot = lower_bound(b+1, b+1+x, b[i]+b[i]) - b - 1;
            ans += chot - 1;
            if(M[b[i]] >= 3)
                ans++;
        }
    }
    cout<<ans;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("tria.inp","r",stdin);
    freopen("tria.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        M[a[i]]++;
        if(M[a[i]] == 1)
            b[++x] = a[i];
    }
    solve();
}