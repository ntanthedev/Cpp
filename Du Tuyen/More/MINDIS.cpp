#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll a[N], n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("MINDIS.inp","r",stdin);
    // freopen("MINDIS.out","w",stdout);
    ll test;
    cin>>n>>test;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1, a+1+n);
    ll x, t, ans;
    while(test--){
        cin>>x;
        if(x > a[n])
            cout<<x - a[n]<<'\n';
        else if(x < a[1])
            cout<<a[1] - x<<'\n';
        else{
        t = lower_bound(a+1, a+1+n, x) - a;
        ans = min(abs(a[t] - x), abs(a[t-1] - x));
        cout<<ans<<'\n';
        }
    }
}
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll q, n, a[N];
void solve(){
    sort(a+1, a+1+n);
    ll x;
    while(q--){
        cin>>x;
        if(x > a[n])
            cout<<x - a[n]<<'\n';
        else if(x < a[1])
            cout<<a[1] - x<<'\n';
        else{
            ll t = lower_bound(a+1, a+1+n, x) - a;
            cout<<min(abs(a[t] - x), abs(a[t-1] - x))<<'\n';
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("MINDIS.inp","r",stdin);
    freopen("MINDIS.out","w",stdout);
    // freopen("a.inp","r",stdin);
    // freopen("a.out","w",stdout);
    cin>>n>>q;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    solve();
}
*/
