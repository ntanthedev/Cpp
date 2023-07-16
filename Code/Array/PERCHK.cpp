#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("PERCHK.inp","r",stdin);
    freopen("PERCHK.out","w",stdout);
    cin.tie(NULL);
    cin>>n;
    long long a[n], DD[n];
    for(int i = 1; i <= n; i++)
        DD[i] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(a[i] > 0 && a[i] <= n)
        DD[a[i]] ++;
    }
    int res = 0;
    for(int x = 1; x <= n; x++)
    {
        if(DD[x] > 1 || DD[x]==0)
        {
            res = x;
            break;
        }
    }
    if(res == 0)
        cout<<"YES";
    else
        cout<<"NO";
}



