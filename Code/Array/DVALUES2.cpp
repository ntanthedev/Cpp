#include<bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    freopen("DVALUES2.inp","r",stdin);
    freopen("DVALUES2.out","w",stdout);
    ios_base::sync_with_stdio(false);
    map<long long, long long>M;
    cin>>n;
    long long a[n + 9];
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(M[a[i]] == 0)
        {
            cout<<a[i]<<" ";
            M[a[i]] = 1;
        }
    }
}
