#include<bits/stdc++.h>
using namespace std;
unsigned long long m, n, t, x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DXB1.inp","r",stdin);
    freopen("DXB1.out","w",stdout);
    cin>>n>>m;
    long long s;
    if(n%2==0)
    {
        s = m*n;
        x = s/2;
        t = s/2;
    }
    else
    {
        s = m*(n-1);
        x = s/2 + m;
        t = s/2;
    }
    cout<<x<<" "<<t;
}
