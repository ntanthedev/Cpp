#include<bits/stdc++.h>
using namespace std;
int const maxn =1e6+4;
int const maxnn =1e3+2;
string x,y;
int m,n,g[maxn][30],f[maxnn][maxnn];
int res(0),cnt(0),k(0);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("LCS2.INP","r",stdin);
    freopen("LCS2.OUT","w",stdout);
    getline(cin,x);x=" "+x;
    getline(cin,y);y=" "+y;
    m=x.length();m=m-1;
    n=y.length();n=n-1;
   for(int i=0;i<=25;i++)
   {
           g[n+1][i]=n+1;g[n+2][i]=n+1;
   }
   for(int i=n;i>=1;i--)
   {
       for(char k='A';k<='Z';k++)
       {
           if(y[i]==k) g[i][k-'A']=i;
           else g[i][k-'A']=g[i+1][k-'A'];
       }
   }
   for(int i=1;i<=m;i++)
   {
       f[0][i]=n+1;
   }
   for(int i=1;i<=m;i++)
   {
       for(int j=1;j<=m;j++)
       {
           f[i][j]=n+1;       }
   }
   for(int i=1;i<=m;i++)
   {
       for(int l=1;l<=m;l++)
       {
           f[i][l]=min(f[i-1][l],g[f[i-1][l-1]+1][x[i]-'A']);
       }
   }
   for(int i=1;i<=m;i++)
   {
       for(int l=1;l<=m;l++)
       {
           if(f[i][l]<=n)
           {
               res=l;
               cnt=i;
           }
       }
   }
   string ans;
   ans.resize(res);
   int l=res;
   while(cnt!=0)
   {
       if(f[cnt][l]!=n+1&&x[cnt]==y[f[cnt][l]])
       {
           ans[l-1]=x[cnt];
           l=l-1;
       }
       cnt--;
   }
   cout<<ans;
}
