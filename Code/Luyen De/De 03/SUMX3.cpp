#include<bits/stdc++.h>
using namespace std;
long long x, n, S = 2022;
long long ct1(long long S)
{
    for(int i = 1; i <= n; i++)
    {
        if(i%2 != 0)
            S += i*x;
        if(i%2 == 0)
            S -= i*x;
    }
    return S;
}
long long ct2(long long S)
{
    long long t;
    if(n%2 == 0)
    {
        t = n/2;
        S = S - t*x;
    }
    if(n%2 != 0)
    {
        t = (n + 1)/2;
        S = S + t*x;
    }
    return S;
}
int main()
{
    cin.tie(NULL);
    freopen("SUMX3.inp","r",stdin);
    freopen("SUMX3.out","w",stdout);
    cin>>n>>x;
    if(n <= 1e6)
        cout<<ct2(S);
    if(n > 1e6)
        cout<<ct2(S);
}
