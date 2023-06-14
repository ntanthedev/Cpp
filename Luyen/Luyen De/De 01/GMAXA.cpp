#include<bits/stdc++.h>
using namespace std;
long long n, a[1000009], gmax = LLONG_MAX;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("GMAXA.inp","r",stdin);
    freopen("GMAXA.out","w",stdout);
    cin>>n;
    for(int i = 1; i <=  n; i++)
    {
        cin>>a[i];
        if(a[i] < gmax && a[i] > )
            gmax = a[i];
    }
    cout<<gmax;
}
