#include<bits/stdc++.h>
using namespace std;
long double denta, a, b, c, x1, x2;
int main()
{
    cin.tie(NULL);
    freopen("QUAE24.inp","r",stdin);
    freopen("QUAE24.out","w",stdout);
    cout<<fixed<<setprecision(4);
    cin>>a>>b>>c;
    denta = b*b - 4*a*c;
    if(denta < 0)
        cout<<"NO SOLUTION";
    if(denta == 0)
        cout<<(-b)/(2*a);
    if(denta > 0)
    {
        x1 = ((-b) - sqrt(denta))/(2*a);
        x2 = ((-b) + sqrt(denta))/(2*a);
        if(x1 < x2)
        {
            cout<<x1<<'\n';
            cout<<x2<<'\n';
        }
        else
        {
            cout<<x2<<'\n';
            cout<<x1<<'\n';
        }

    }
}
