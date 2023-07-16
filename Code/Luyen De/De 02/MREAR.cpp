#include<bits/stdc++.h>
using namespace std;
long long x1, y1, x2, y2, S, gmin = LLONG_MAX;
int main()
{
    cin.tie(NULL);
    freopen("MREAR.inp","r",stdin);
    freopen("MREAR.out","w",stdout);
    for(int i = 1; i <= 3; i++)
    {
        cin>>x1>>y1>>x2>>y2;
        S = abs(x1 - x2)*abs(y1 - y2);
        gmin = min(gmin, S);
    }
    cout<<gmin;
}
