#include<bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SORTF.inp","r",stdin);
    freopen("SORTF.out","w",stdout);
    cin>>n;
    long long a[n], b[n];
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1, a+1+n);
    long i = 1, j = n;
    for(int k = 1; k <= n; k++)
        if(a[k]%2 == 0)
            b[i++] = a[k];
        else
            b[j--] = a[k];
    for(int x = 1; x <= n; x++)
        cout<<b[x]<<" ";
}
