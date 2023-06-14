#include<bits/stdc++.h>
using namespace std;
long double s, l, a, b, c, denta;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("ESIZE5.inp","r",stdin);
    freopen("ESIZE5.out","w",stdout);
    cout<<fixed<<setprecision(2);
    cin>>l>>s;
    l = l/2;
    denta = (l*l) - 4*s;
    if(denta == 0)
    {
        a = (-l)/2;
        b = (-l)/2;
    }
    if(denta > 0)
    {
        a = (-l - sqrt(denta))/2;
        b = (-l + sqrt(denta))/2;
    }
    if(a >= b)
    {
        cout<<a*(-1)<<'\n';
        cout<<b*(-1)<<'\n';
    }
    else
    {
        cout<<b*(-1)<<'\n';
        cout<<a*(-1)<<'\n';
    }
}
//x^2 - lx + s = 0;
