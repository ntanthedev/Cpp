#include<bits/stdc++.h>
using namespace std;
long long n, a[1000009], gmin = LLONG_MAX, dem = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("SSUMMIN.inp","r",stdin);
    //freopen("SSUMMIN.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        dem = min(a[i], dem + a[i]);
        gmin = min(gmin, dem);
    }
    cout<<gmin;
}
