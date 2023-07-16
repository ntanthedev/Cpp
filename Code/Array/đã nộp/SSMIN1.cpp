#include<bits/stdc++.h>
using namespace std;
long long a[100000099], n;
int main()
{
    freopen("SSMIN1.inp","r",stdin);
    freopen("SSMIN1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    long long m = a[1], S;
    for(int i = 1; i <= n; ++i)
        if(a[i] < m)
            m = a[i];
    for(int i = 1; i <= n; ++i)
    {
        S = 0;
        for(int j = i; j < n; ++j)
        {
            S += a[j];
            m = min(m, S);
        }
    }
    cout<<m;
}
