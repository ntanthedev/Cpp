#include<bits/stdc++.h>
using namespace std;
long long n,k,m,i,j,a[1000005],d[1000005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("DAYDEN.INP","r",stdin);
    freopen("DAYDEN.OUT","w",stdout);
    cin>>n>>k>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a[i];
        for(j=1;j<=n/a[i];j++)
        {
            d[j*a[i]]++;
        }
    }
int dem=0;
for(i=1;i<=n;i++)
{
    if(d[i]%2==0)dem++;
}
cout<<dem;
    return 0;
}
