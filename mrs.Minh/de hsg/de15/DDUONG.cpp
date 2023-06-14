#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000068],s,u,v;
void doc()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
}
void xuly()
{
    for(int i=1;i<=n;i++)
    {
        s=0;
        for(int j=i;j<=n;j++)
        {
            s=s+a[j];
            if((s/(j-i+1))==k)
            {
                u=j-i+1;
                v=i;
            }
        }
    }
    cout<<u<<'\n';
    cout<<v;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DDUONG.INP","r",stdin);
    freopen("DDUONG.OUT","w",stdout);
    doc();
    xuly();
}