#include<bits/stdc++.h>
#define fi first 
#define se second
using namespace std;
typedef long long ll;
const ll N1=1e3,N2=1e6;
ll n,k,maxx=0,M[3000021];
pair<ll,ll>a[1000021];
void sub1()
{
    sort(a+1,a+n+1);
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        ll save=a[i].se,pos=i+1;
        for(ll j=a[i].fi+1;j<=min(a[i].fi+2*k,N1);j++)
        {
            if(pos==(n+1)) break;
            if(j==a[pos].fi) 
            {
                save+=a[pos].se;
                pos++;
                if(pos==(n+1)) break;
            }
        }
        ans=max(ans,save);
    }
    cout<<ans;
}
void sub2()
{
    sort(a+1,a+n+1);
    ll r=2;
    ll ans=a[1].se,save=0;
    for(ll i=1;i<=n;i++)
    {
        if(!save) save+=a[i].se;
        if(r<=i) r=i+1;
        while(r<=n && (a[i].fi+2*k)>=a[r].fi) 
        {
            save+=a[r].se;
            r++;
        }
        ans=max(ans,save);
        //cout<<ans<<" ";
        if(i<n && a[i].fi!=a[i+1].fi) save-=a[i].se;
    }
    cout<<ans;
}
void sub3()
{
    for(ll i=1;i<=n;i++)
    {
        M[a[i].fi]+=a[i].se;
    }
    ll ans,save=M[1];
    for(ll i=2;i<=min(2*k+1,N2);i++)
    {
        save+=M[i];
    }
    ans=save;
    for(ll i=2;i<=1000000;i++)
    {
        save-=M[i-1];
        if(k<=N2) save+=M[i+2*k];
        ans=max(ans,save);
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("test.inp","r"))
    {
        freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
    }
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i].fi>>a[i].se;
        maxx=max(a[i].fi,maxx);
    }
    if(n<=1e3 && maxx<=1e3) sub1();
    else if(n<=1e5 && maxx>=1e6 && maxx<=1e9) sub2();
    else if(n<=1e6 && maxx<=1e6) sub3();
}
