#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll n,s,d,the,dem,dd;
ll sum(int i)
    {
        int t=0;
        while(i!=0)
            {
                t=t+i%10;
                i=i/10;
                dd++;
            }
        return t;
    }
ll poww(int m,int n)
    {ll t=1;
        for(int i=1;i<=m;i++)
            {
                t=t*n;
            }
        return t;
    }
ll reverse(int x)
    {
        ll t=0;
        for(int i=1;i<=dd;i++)
            {
                t=t*10+x%10;
                x=x/10;
            }
        return t;
    }
void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
//    freopen("Palnums.inp","r",stdin);
    //  freopen("Palnums.out","w",stdout);
cin>>n>>s;
the=n;
while(the!=0)
    {
        d++;
        the=the/10;
    }
if(s>9*d)
    {
        cout<<1;
        return 0;
    }
ll n2;
n2=n;
for(int i=1;i<d/2;i++)
    {
        n2=n2/10;
    }
for(int i=1;i<10;i++)
    {
        if(i%s==0&&i<=n)
            {
                dem++;
            }
    }
//cout<<n2<<endl;
for(int i=1;i<=n2;i++)
    {dd=0;
        ll t=0,gt,kq,x;
        kq=sum(i);
        x=reverse(i);
        t=kq-i%10+kq;
        
       if(dd>1)gt=i*poww(dd-1,10)+x%10;
       else gt=n+1;
       //  cout<<t<<" "<<gt<<" "<<i<<" "<<dd<<endl;
        if(t%s==0&&gt<=n)dem++;
        t=kq*2;
        gt=i*poww(dd,10)+x;
       // cout<<t<<" "<<gt<<" "<<i<<" "<<x<<endl;
        if(t%s==0&&gt<=n)dem++;

    }
cout<<dem;



    solve();
}