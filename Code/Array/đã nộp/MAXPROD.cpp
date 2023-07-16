#include<bits/stdc++.h>
using namespace std;
long long a[100000022], n;
int main()
{
    freopen("MAXPROD.inp","r", stdin);
    freopen("MAXPROD.out","w", stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    sort(a+1, a+1+n);
    long long x, y;
    x = a[n]*a[n - 1];
    y = a[1]*a[2];
    if(x>y)
        cout<<x;
    else
        cout<<y;
}
