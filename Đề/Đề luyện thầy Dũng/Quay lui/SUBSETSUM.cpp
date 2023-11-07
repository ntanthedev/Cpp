#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10006],dem,b[10007],w,q(1),x[10009],kt,t[10006];
bool stop;
void QL(long long i,long long s)
{  if(i>n)
   { if(s==m)
    {   cout<<"YES"<<'\n';
        for(long long k=1;k<=n;k++)
        {if(x[k]==1) cout<<k<<" ";  }
        stop=true;
    }
       return; 
    }
    for(int j=1;j>=0;j--)
    {
        x[i]=j;
        if(stop) return;
        if(s+j*a[i]>m || s+t[n]-t[i]+j*a[i]<m ) continue;
            QL(i+1,s+j*a[i]);
    }
}
int main()
{
    freopen("SUBSETSUM.inp","r",stdin);
    freopen("SUBSETSUM.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {cin>>a[i];
     t[i]=t[i-1]+a[i];
    }
    QL(1,0);
    if(stop==false) cout<<"NO";
}



