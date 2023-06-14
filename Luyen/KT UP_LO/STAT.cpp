#include<bits/stdc++.h>
using namespace std;
const long long maxN = 100022;
long long a[maxN], n, b[maxN], smax, smin;
int main()
{
    freopen("STAT.inp","r",stdin);
    freopen("STAT.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b+1, b+1+n);
    for(int i = 1; i <= n; ++i)
    {
        smin = lower_bound(b+1,b+1+n,a[i]) - b - 1;
        smax = n - (upper_bound(b+1, b+1+n,a[i]) - b) + 1;
        cout<<smin<<" "<<smax<<'\n';
    }
}
