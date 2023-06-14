#include <bits/stdc++.h>
using namespace std;
long long n,x,y;
unsigned long long S,S1;
long long dao(long long m)
{
    long long s=0,du=0;
    while(m!=0)
    {
        du=m%10;
        m=m/10;
        s=(s*10)+du;
    }
    return s;
}
int main()
{
    freopen("PALIND.inp","r",stdin);
    freopen("PALIND.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        S=x+y;
        S1=dao(S);
        if(S==S1)
            cout<<1<<'\n';
        else cout<<0<<'\n';
        S=0;
    }
   return 0;
}