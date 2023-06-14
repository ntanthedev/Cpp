#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e3+9;
ll a, b, n, r[N][N], d[4001],gmin = 1e10;
ll k[4001], kq[4001];
void output(ll z){
    for(int i = 1; i <= z; i++){
        cout<<kq[z]<<" ";
    }
    cout<<'\n';
}
void tim(int i){
    for(int j = 1; j <= n; j++){
        if(i <= gmin && r[k[i-1]][j] == 1){
            if(d[j] == 0){
                k[i] = j;
                d[j] = 1;
                if(j == b && i <= gmin){
                    gmin = i;
                    kq = k;
                }
            }
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("xebuyt.inp","r",stdin);
    freopen("xebuyt.out","w",stdout);
    
    solve();
}
/* 
#include <bits/stdc++.h>
using namespace std;
int n,a,b,ans,x,y,c[4001],d[1001],r[1001][1001],k[4001],kq[4001],mn;
void inra(int z)
{
    for(int i=0;i<=z;i++)
        cout<<kq[i]<<" ";
    cout<<'\n';
}
void tim(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(i<=mn)
        {
            if(r[k[i-1]][j]==1)
            {
                if(d[j]==0)
                {
                    k[i]=j; d[j]=1;
                    if(j==b) {
                        if(i<=mn) {
                            mn=i;
                            for(int p=1;p<=mn;p++)
                            {
                                kq[p]=k[p];
                            }
                        }
                    }
                    else tim(i+1);
                    d[j]=0;
                }
            }
        }
    }
}
int main()
{
    freopen("XEBUYT.inp","r",stdin);
    freopen("XEBUYT.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>a>>b;
    mn=41;
    ans=0;
    while(cin>>x>>y)
    {
        ans++;
        r[x][y]=1;
        r[y][x]=1;
    }
    k[0]=a; kq[0]=a; d[a]=1;
    tim(1);
    if(mn!=41) inra(mn);
    else cout<<"-1";
}
 */