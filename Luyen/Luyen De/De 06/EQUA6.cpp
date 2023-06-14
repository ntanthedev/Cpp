#include<bits/stdc++.h>
using namespace std;
long double a1, b1, c1, a2, b2, c2, Dx, Dy, D, x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("EQUA6.inp","r",stdin);
    freopen("EQUA6.out","w",stdout);
    cin>>a1>>b1>>c1;
    cin>>a2>>b2>>c2;
    D = (a1*b2) - (a2*b1);
    Dx = (c1*b2) - (c2*b1);
    Dy = (a1*c2) - (a2*c1);
    if(D != 0)
    {
        x = Dx/D;
        y = Dy/D;
        cout<<fixed<<setprecision(2)<<x<<" "<<y;
    }
    else if(Dx + Dy != 0)
        cout<<"NO SOLUTION";
    else if(D == 0 && Dx + Dy == 0)
        cout<<"INFINITE";

}
//x = Dx/D
//y = Dy/D
