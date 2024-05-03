```
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
void solve() {
    //initialize
    ll n,k,x,y;
    cin>>n>>k>>x>>y;
    vector<ll>a(n+1),b(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    if(k<2*n)
    {
    vector<ll>c(k+1),d(k+1);
    c[0]=a[x];
    d[0]=b[y];
    for(ll i=1;i<=k;i++)
    {
        c[i]=c[i-1];
        if((i+x)<=n) c[i]=max(c[i],a[i+x]);
        if((x-i)>=1) c[i]=max(c[i],a[x-i]);
    }
    for(ll i=1;i<=k;i++)
    {
        d[i]=d[i-1];
        if((i+y)<=n) d[i]=max(d[i],b[i+y]);
        if((y-i)>=1) d[i]=max(d[i],b[y-i]);
    }
    ll ans=0;
    for(ll i=0;i<=k;i++)
    {
        ans=max(ans,c[i]+d[k-i]);
    }
    cout<<ans;
    }
    else
    {
        ll d=0,dd=0;
    for(ll i=n;i>=1;i--)
    {
        d=max(d,a[i]);
    }
    for(ll i=n;i>=1;i--)
    {
        dd=max(dd,b[i]);
    }
    cout<<dd+d;
    }
    //solve
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("L.inp","r"))
    {
    freopen("L.inp","r",stdin);
    freopen("L.out","w",stdout);
    }
    solve();
//---writer---
}
/*
▓██   ██▓ █    ██  ███▄ ▄███▓▓█████   ██████ ▓█████  ██ ▄█▀▄▄▄       ██▓
▒██  ██▒ ██  ▓██▒▓██▒▀█▀ ██▒▓█   ▀ ▒██    ▒ ▓█   ▀  ██▄█▒▒████▄    ▓██▒
▒██ ██░▓██  ▒██░▓██    ▓██░▒███   ░ ▓██▄   ▒███   ▓███▄░▒██  ▀█▄  ▒██▒
░ ▐██▓░▓▓█  ░██░▒██    ▒██ ▒▓█  ▄   ▒   ██▒▒▓█  ▄ ▓██ █▄░██▄▄▄▄██ ░██░
░ ██▒▓░▒▒█████▓ ▒██▒   ░██▒░▒████▒▒██████▒▒░▒████▒▒██▒ █▄▓█   ▓██▒░██░
██▒▒▒ ░▒▓▒ ▒ ▒ ░ ▒░   ░  ░░░ ▒░ ░▒ ▒▓▒ ▒ ░░░ ▒░ ░▒ ▒▒ ▓▒▒▒   ▓▒█░░▓  
▓██ ░▒░ ░░▒░ ░ ░ ░  ░      ░ ░ ░  ░░ ░▒  ░ ░ ░ ░  ░░ ░▒ ▒░ ▒   ▒▒ ░ ▒ ░
▒ ▒ ░░   ░░░ ░ ░ ░      ░      ░   ░  ░  ░     ░   ░ ░░ ░  ░   ▒    ▒ ░
░ ░        ░            ░      ░  ░      ░     ░  ░░  ░        ░  ░ ░ 
░ ░
*/
```