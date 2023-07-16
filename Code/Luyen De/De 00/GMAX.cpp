#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, gmax;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("GMAX.inp","r",stdin);
    freopen("GMAX.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    gmax = a[1];
    for(int i = 1; i <= n; ++i)
        if(a[i] > gmax)
            gmax = a[i];
    cout<<gmax;
}
