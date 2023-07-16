#include<bits/stdc++.h>
using namespace std;
long long a, b;
long double x;
int main()
{
    freopen("PTBN.inp","r",stdin);
    freopen("PTBN.out","w",stdout);
    cin.tie(NULL);
    cin>>a>>b;
    if(a == 0 && b != 0)
        cout<<"VO NGHIEM";
    if(a == 0 && b == 0)
        cout<<"VO SO NGHIEM";
    if(a != 0)
    {
        x = (double(-b))/a;
        cout<<fixed<<setprecision(3);
        cout<<x;
    }
}
