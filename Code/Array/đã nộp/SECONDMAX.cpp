#include<bits/stdc++.h>
using namespace std;
long long a[100000022], n, v = 0;
int main ()
{
    freopen("SECONDMAX.inp", "r", stdin);
    freopen("SECONDMAX.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    //dong 1
    long long max = a[1];
    for(int i = 1; i <= n; ++i)
        if(a[i] > max)
            max = a[i];
    for(int i = 1; i <= n; ++i)
        if(a[i] > v && a[i] < max)
            v = a[i];
    cout<<v<<'\n';
    //dong 2
    for(int i = 1; i <= n; ++i)
        if(a[i] == v)
            cout<<i<<" ";

}
//if(a[i] > v && a[i] < max)
