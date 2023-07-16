#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, gmin, dem = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SSMIN.inp","r",stdin);
    freopen("SSMIN.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        dem = min(a[i], dem + a[i]);
        gmin = min(gmin, dem);
    }
    cout<<gmin;
}
/*gmin = a[1];
    for(int i = 1; i <= n; i++)
    {
        dem = min(a[i], dem + a[i]);
        gmin = min(gmin, dem);
    }*/
