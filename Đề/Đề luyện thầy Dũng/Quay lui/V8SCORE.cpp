#include<bits/stdc++.h>
using namespace std;
long long n,a[100][100],b[1000168],d=0,m,p[1000168],k;
vector<long long>f;
bool kt;
int tmp=0;
void ql(long long i,long long s)
{
    if(i>n)
    {
        if(s==m)
     {
        d=0;
             cout<<"YES"<<'\n';
              for(int k=1;k<=n;k++)
            cout<<a[b[k]][k]<<" ";
            kt=true;
     }
        return;
    }
     if(kt) return;
 for (int j=1;j<=k;j++)
 {
      if((a[j][i])>=(a[b[i-1]][i-1]))
      {
         b[i]=j;
         if(kt) return;
         if(s+a[j][i]>m||s+p[n]-p[i]+a[j][i]<m) continue;
         ql(i + 1,s+a[j][i]);
 }
 }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if(fopen("V8SCORE.inp","r"))
  { freopen("V8SCORE.inp","r",stdin);
    freopen("V8SCORE.out","w",stdout);
  }
    cin>>m>>n>>k;
    for(int j=1;j<=n;j++)
        p[j]=0;
    for(int i=1;i<=k;i++)
    {
      for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        p[j]=max(p[j],a[i][j]);
    }
    }
    p[0]=0;
    for(int j=1;j<=n;j++)
        p[j]=p[j-1]+p[j];
    kt=false;
   ql(1,0);
   if(kt==false) cout<<"NO";
}
