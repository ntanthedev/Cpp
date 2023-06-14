#include<bits/stdc++.h>
using namespace std;
long long n, a[1000009], k, gmax = LLONG_MIN;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("MDIVK6.inp","r",stdin);
    freopen("MDIVK6.out","w",stdout);
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(a[i] > gmax && a[i]%k == 0)
            gmax = a[i];
    }
    cout<<gmax;
}
