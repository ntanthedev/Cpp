#include<bits/stdc++.h>
using namespace std;
long long n;
long double a, l;
int main()
{
    cin.tie(NULL);
    freopen("TIETKIEM1.inp","r",stdin);
    freopen("TIETKIEM1.out","w",stdout);
    cin>>a>>n;
    for(int i = 1; i <= n; i++)
    {
        l = (a*0.3)/1000;
        a += l;
    }
    cout<<fixed<<setprecision(3);
    cout<<a;
}/*
#include<bits/stdc++.h>
using namespace std;
long double a,n,x,y;
long long i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("TIETKIEM1.INP","r",stdin);
    freopen("TIETKIEM1.OUT","w",stdout);
    cin>>x>>y;
    a=x;
    for(i=1;i<=y;i++)
    {
        a=a+((a*0.3)/100);
    }
    cout<<fixed<<setprecision(3)<<a;
}
*/
