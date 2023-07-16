#include<bits/stdc++.h>
using namespace std;
long long a[10000022], n;
int main()
{
    freopen("DVALUES1.inp","r",stdin);
    freopen("DVALUES1.out","w",stdout);
    ios_base::sync_with_stdio(false);
    map<long long, long long>M;
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        cin>>a[i];
        M[a[i]]++;
    }
    for(int x = 1e3; x >= -1e3; x--)
        if(M[x] != 0)
            cout<<x<<" ";
}
