#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("PERNUM.inp","r",stdin);
    freopen("PERNUM.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1, a+1+n);
    t = max(abs(a[1] + a[2]), abs(a[n] + a[n - 1]));
    cout<<t;
}
