#include<bits/stdc++.h>
using namespace std;
long long n, a[100009], mmax = 0, gmin, dem = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("DISNUM3.INP","r",stdin);
    freopen("DISNUM3.OUT","w",stdout);
    cin>>n;
    map<long long, long long>D;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        D[a[i]]++;
    }
    gmin = a[1];
    for(int i = 1; i <= n; i++)
    {
        if(D[a[i]] == mmax && a[i] < gmin)
            gmin = a[i];
        if(D[a[i]] > mmax)
        {
            mmax = D[a[i]];
            gmin = a[i];
        }
    }
    cout<<gmin<<" "<<mmax;
}