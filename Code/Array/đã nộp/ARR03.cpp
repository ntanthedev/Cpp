#include<bits/stdc++.h>
using namespace std;
long long a[100000022], n;
bool cp(long long x)
{
    int i;
    i = sqrt(x);
    if(i*i == x)
        return 1;
    return 0;
}
bool shh(long long x)
{
    long long t = 0;
    for(int i = 1; i <= x/2; i++)
        if(x%i == 0)
            t += i;
    if(t == x)
        return 1;
    return 0;
}
bool nt(long long x)
{
    if(x < 2)
        return 0;
    for(int i = 2; i <= sqrt(x); i++)
        if(x%i == 0)
            return 0;
    return 1;
}
int main ()
{
    freopen("ARR03.inp", "r", stdin);
    freopen("ARR03.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    //dong 1, 2, 3
    long long count1 = 0, count2 = 0, count3 = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(cp(a[i]) == 1)
            count1 += 1;
        if(shh(a[i]) == 1)
            count2 += 1;
        if(nt(a[i]) == 1)
            count3 += 1;
    }
    cout<<count1<<'\n';
    cout<<count2<<'\n';
    cout<<count3<<'\n';
    //dong 4
    long long count4 = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i; j <= n; ++j)
        {
            if(a[j] == a[i])
                count4 += 1;
        }
        count4 -= 1;
    }
    cout<<count4<<'\n';
    //dong 5
    long long dem = 0, tong;
    for(int i = 1; i < n; ++i)
    {
        for(int j = i + 1; j <= n; ++j)
        {
            tong = a[i] + a[j];
            if(nt(tong) == 1)
                dem += 1;
        }
    }
    cout<<dem<<'\n';
}
