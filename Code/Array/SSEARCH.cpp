#include<bits/stdc++.h>
using namespace std;
long long n, a[10000022];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SSEARCH.inp", "r", stdin);
    freopen("SSEARCH.out", "w", stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    long long x1, x2, x;
    cin>>x;
    x1 = x;
    x2 = x;
    for(int i = 1; i <= n; i++)
        if(a[i] >= x1){
            x1 = i;
            break;}
    if(x1 != x)
        cout<<x1<<'\n';
    else
        cout<<"-1"<<'\n';
    for(int j = n; j >= 1; j--)
        if(a[j] < x2){
            x2 = j;
            break;}
    if(x2 != x)
        cout<<x2<<'\n';
    else
        cout<<"-1"<<'\n';
}
