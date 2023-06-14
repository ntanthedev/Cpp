#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1000009;
ll a[N];
ll cdd[N];
ll cda[N];
ll tmp[N];
ll n;
ll dd[N];
ll minn(0);
ll maxx(0);
ll gmax(0);
void nm_dz_chu_ai_ma_nhin_lam_vay()
{
    cin>>n;
    //tmp[0] = 0;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        if (a[i]>0) cdd[i]=cdd[i-1]+1;
        else cdd[i]=cdd[i-1];
        if (a[i]<0) cda[i]=cda[i-1]+1;
        else cda[i]=cda[i-1];
    }
    for (int i=1;i<=n;i++)
    {
        tmp[i]=cdd[i]-cda[i];
        if (dd[tmp[i]]==0)dd[tmp[i]]=i;
    }
    for (int i=1;i<=n;i++)
    {
        if (i-dd[tmp[i]]>gmax)
        {
            gmax=i-dd[tmp[i]];
            minn=dd[tmp[i]]+1;
            maxx=i;
        }
    }
    cout<<minn<<" "<<maxx;
}
int main()
{
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    nm_dz_chu_ai_ma_nhin_lam_vay();
}