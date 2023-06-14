#include<bits/stdc++.h>
using namespace std;
long long n, a[100009];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("DVALUES3.INP","r",stdin);
    freopen("DVALUES3.OUT","w",stdout);
    cin>>n;
    map<long long, long long>D;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        D[a[i]]++;
    }
    sort(a+1, a+1+n);
    for(int i = n; i >= 1; i--)
    {
        if(D[a[i]] != 0)
        {
            cout<<a[i]<<" "<<D[a[i]]<<'\n';
            D[a[i]] = 0;
        }
    }
}
