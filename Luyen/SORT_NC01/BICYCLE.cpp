#include<bits/stdc++.h>
using namespace std;
unsigned long long a[1000008], n, gmax = LLONG_MIN;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("BICYCLE.inp","r",stdin);
    freopen("BICYCLE.out","w",stdout);
    cin>>n;
    long long x = 2*n;
    for(int i = 1; i <= x; i++)
        cin>>a[i];
    sort(a+1,a+1+x);
    for(int i = 1; i <= n; i++)
        if(a[i] + a[2*n - i+1] > x)
            x = a[i] + a[2*n - i+1];

    cout<<gmax;
}
