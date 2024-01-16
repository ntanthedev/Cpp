#include<bits/stdc++.h>
using namespace std;
const int maxM = 1e3;
const int maxN= 1e6;
const int infty = maxN + 1;
long int i,j,k,f[maxM+1][maxM+1],m,n,x[maxN+5],y[maxN+5],pos[maxN+1][26],t1,t2;
string a,b,z;
void Init()
{
    for(i=0;i<=m;i++) f[i][0]=0;
    for(k=0;k<=25;k++) pos[n+1][k]=infty;
    for(i=n;i>=1;i--)
    {
        for(int k=0;k<=25;k++)
        {
            pos[i][k]=pos[i+1][k];
        }
        j=y[i];
        pos[i][j]=i;
    }
}
void optimize()
{
    for(i=0;i<=m;i++) f[i][0]=0;
    for(int i=1;i<=m;i++)
    {
        for(int k=1;k<=i;k++)
        {
            if(i>k) t1 = f[i - 1][k];
            else  t1 = infty;
            j = f[i - 1][k - 1];
            if(j!=infty) t2=pos[j+1][x[i]];
            else t2 = infty;
            if (t1<t2) f[i][k] = t1;
            else f[i][k]= t2;

        }
    }
}
void dotrace()
{
    int res=m;
    while(res>0 && f[m][res]==infty) res--;
    z.resize(res);
    k=res; i=m;
    while(k!=0)
    {
        j=f[i][k];
        z[--k]=y[j]+'A';
        while(x[i]!=y[j]) i--;
        i--;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("LCS2.INP","r",stdin);
    freopen("LCS2.OUT","w",stdout);
    cin >>a >>b;
    m=a.length(); n=b.length();
    for(int i=1;i<=m;i++)
    {
        x[i]=a[i-1]-'A';
    }
    for(int i=1;i<=n;i++)
    {
        y[i]=b[i-1]-'A';
    }
    Init();
    optimize();
    dotrace();
    cout<<z;
}
