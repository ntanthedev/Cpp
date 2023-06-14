#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, res = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SSDIV3.inp","r",stdin);
    freopen("SSDIV3.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(a[i]%3 == 0 && a[i]%2 != 0)
            res += a[i];
    }
    cout<<res;
}
