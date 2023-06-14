#include<bits/stdc++.h>
using namespace std;
long long a[100000022], n, k;
int main ()
{
    freopen("ARR02.inp", "r", stdin);
    freopen("ARR02.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    //dong 1
    long long maxd = a[1], mina = a[1];
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] > maxd)
            maxd = a[i];
        if(a[i] < mina)
            mina = a[i];
    }
    long long maxa = mina, mind = maxd, maxc = 0, minl = maxd, demmax = 0, demk = 0, ik, chiak = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] > maxa && a[i] < 0)
            maxa = a[i];
        if(a[i] < mind && a[i] > 0)
            mind = a[i];
        if(a[i]%2 == 0 && a[i] > maxc)
            maxc = a[i];
        if(a[i]%2 != 0 && a[i] < minl && a[i] > 0)
            minl = a[i];
        if(a[i] == maxd)
            demmax += 1;
        if(a[i] == k)
            demk += 1;
        if (a[i] > 0 && a[i]%k == 0)
            chiak += 1;
    }
        for(int i = 1; i <= n; ++i)
        {
            if(a[i] == k)
            {
                ik = i;
                break;
            }
            else
                ik = 0;

        }
    cout<<maxd<<'\n';
    cout<<mina<<'\n';
    cout<<maxa<<'\n';
    cout<<mind<<'\n';
    cout<<maxc<<'\n';
    cout<<minl<<'\n';
    cout<<demmax<<'\n';
    cout<<demk<<'\n';
    cout<<ik<<'\n';
    cout<<chiak<<'\n';
}
