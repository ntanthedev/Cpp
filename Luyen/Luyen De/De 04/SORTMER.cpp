#include<bits/stdc++.h>
using namespace std;
long long a[1000009], b[1000009], m, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("SORTMER.inp","r",stdin);
    freopen("SORTMER.out","w",stdout);
    cin>>m>>n;
    for(int i = 1; i <= m; i++)
        cin>>a[i];
    for(int i = 1; i <= n; i++)
        cin>>b[i];
    long long i = 1, j = 1;
    while(i <= m && j <= n)
    {
        if(a[i] <= b[j])
        {
            cout<<a[i]<<" ";
            i++;
        }
        if(b[j] <= a[i])
        {
            cout<<b[j]<<" ";
            j++;
        }
    }
    while(i <= m)
    {
        cout<<a[i]<<" ";
        i++;
    }
    while(j <= n)
    {
        cout<<b[j]<<" ";
        j++;
    }
}
