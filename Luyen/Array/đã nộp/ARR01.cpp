#include<bits/stdc++.h>
using namespace std;
long long a[100000022], n;
int main ()
{
    freopen("ARR01.inp", "r", stdin);
    freopen("ARR01.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    //dong 1
    for(int i = 1; i <= n; ++i)
        if(a[i] > 0)
            cout<<i<<" ";
        cout<<'\n';
    //dong 2
    cout<<a[n] - a[1];
    cout<<'\n';
    //dong 3, 4, 5, 7
    long long S3 = 0, S4 = 0, count = 0;
    for(int i = 1; i <= n; ++i)
    {
        S3 += a[i];
        S4 += abs(a[i]);
        count += 1;
    }
    cout<<S3<<'\n';
    cout<<S4<<'\n';
    cout<<fixed<<setprecision(2);
    cout<<(long double)S3/count<<'\n';
    //dong 6
    long long S6 = 0;
    for(int i = 2; i <= n; i += 2)
        S6 += a[i];
    cout<<S6<<'\n';
    //dong 7, 8
    long long S7 = 0, S8 = 0, S9 = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(a[i]%2 != 0)
            S7 += 1;
        if(a[i] > 0)
            S8 += 1;
        if(i%2 != 0 && a[i] < 0)
            S9 += a[i];
    }
    cout<<S7<<'\n';
    cout<<S8<<'\n';
    cout<<S9<<'\n';
    //dong 10
    long long S10 = 0;
    for(int i = 2; i <= n; i += 2)
        if(a[i] > 0 && a[i]%2 == 0)
            S10 += a[i];
    cout<<S10<<'\n';
}
