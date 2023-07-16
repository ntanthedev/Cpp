#include<bits/stdc++.h>
using namespace std;
long long n, a[1000009], dem = 1, gmax = 0;
int main()
{
    //freopen("INCSEG.inp","r",stdin);
    //freopen("INCSEG.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    cin>>a[1];
    for(int i = 2; i <= n; i++)
    {
        cin>>a[i];
        if(a[i] >= a[i-1])
            dem++;
        else
            dem = 1;
        gmax = max(gmax, dem);
    }
    cout<<gmax;
}
