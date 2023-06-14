#include<bits/stdc++.h>
using namespace std;
long long a[100000022], n, k;
int main()
{
    freopen("ANTS.inp", "r", stdin);
    freopen("ANTS.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    long long vt = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] > 0)
        {
            if(k - a[i] > vt)
                vt = k - a[i];
        }
        else
            if(abs(a[i]) > vt)
                vt = abs(a[i]);
    }
    cout<<vt;
}
