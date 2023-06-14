#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000009], b[1000009], n,x ;
const ll MOD = 1e9+7, N = 1e5;
void pt(ll a[], ll x)
{
    for(int i = 2; i*i <= x; i++){
        while(x%i == 0){
            x/= i;
            a[i]++;
        }
    }
    if(x > 1)
        a[x]++;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("UCLN.inp","r",stdin);
    freopen("UCLN.out","w",stdout);
    a[1] = b[1] = 1;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>x;
        pt(a,x);
    }
    cin>>n;
    for(int i = 1;i <= n; i++){
        cin>>x;
        pt(b,x);
    }
    ll ans = 1;
    for(int i = 1; i <= N; i++){
        if(a[i] == 0 || b[i] == 0)
            continue;
        ll r = min(a[i], b[i]);
        for(int j = 1; j <= r; j++){
            ans *= i;
            if(ans >= MOD)
                ans %= MOD;
        }
    }
    cout<<ans;
}
/*
#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
}
*/
