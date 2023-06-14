	#include<bits/stdc++.h>
using namespace std;
long long n,x,i,vt,y,vt1;
struct pt
{
    int vt;
    long long gt;
};
 pt a[1000008];
bool cmp(pt x,pt y)
{
    return(x.gt<y.gt||(x.gt==y.gt && x.vt<y.vt));

}

bool cmp1(pt x,pt y)
 {
    return(x.gt>y.gt||(x.gt==y.gt && x.vt<y.vt));
 }

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
        freopen("SORTF2.inp","r",stdin);
     freopen("SORTF2.out","w",stdout);
     cin>>n;
     for(int i=1;i<=n;i++)
     {
        cin>>a[i].gt;
        a[i].vt=i;
     }
     sort(a+1,a+n+1,cmp);
      for(int i=1;i<=n;i++)
        if(a[i].gt%2==0)cout<<a[i].vt<<" ";
       sort(a+1,a+n+1,cmp1);
       for(int i=1;i<=n;i++)
         if(a[i].gt%2!=0)
         cout<<a[i].vt<<" ";


}
