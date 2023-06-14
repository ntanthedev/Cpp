#include<bits/stdc++.h>
using namespace std;
struct S{
long long a;
long long b;
long long s;

};
bool cmp(S&x,S&y)
    {
        return x.s>y.s;
    }
S x[1000005];
long long n,p,m,i,j;
int main(){
//freopen("thu.inp","r",stdin);
ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);
cin>>n>>m>>p;
for(i=1;i<=n;i++)
{
    cin>>x[i].a>>x[i].b;
    x[i].s=x[i].a-1-x[i].b;
}
sort(x+1,x+n+1,cmp);
cout<<abs(x[m].s);
    return 0;
}