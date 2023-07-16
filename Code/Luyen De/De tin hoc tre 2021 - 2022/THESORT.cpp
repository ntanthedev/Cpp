#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, gmin, gmax;
int main()
{
    freopen("THESORT.inp","r",stdin);
    freopen("THESORT.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        gmin = min(gmin, a[i]);
        gmax = max(gmax, a[i]);
    }
    if(gmin < 0)
        if(gmax < 0)
            cout<<abs(gmin*2);
        else
            cout<<(abs(gmin) + gmax)*2;
    else
        cout<<gmax*2;
}
