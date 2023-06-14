#include<bits/stdc++.h>
using namespace std;
long long a, b, c, m;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    freopen("ISTRIA.inp","r",stdin);
    freopen("ISTRIA.out","w",stdout);
    cin>>a>>b>>c;
    a = a*a;    b = b*b;    c = c*c;
    if(a + b == c || b + c == a || a + c == b)
        cout<<0;
    else if(a + b < c || a + c < b || b + c < a)
        cout<<2;
    else
        cout<<1;
}
