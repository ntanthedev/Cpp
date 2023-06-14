#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long x1, x2, y1, y2, u1, u2, v1, v2, a, b;

    cin>>x1>>y1>>x2>>y2;
    cin>>u1>>v1>>u2>>v2;

    a = abs(x1-x2)*abs(y1-y2);
    b = abs(u1-u2)*abs(v1-v2);
    if (a>b)
        cout<<a;
    else
        cout<<b;
        return 0;

}
