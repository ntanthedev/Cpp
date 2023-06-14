#include<bits/stdc++.h>
using namespace std;
long long dem = 0, n, gmax, gmin, x, y, kq;
map<long long, long long>M;
int main()
{
    cin.tie(NULL);
    freopen("FIND.inp","r",stdin);
    freopen("FIND.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>x>>y;
        gmax = max(gmax, y);
        gmin = min(gmin, x);
        for(int j = x; j < y; j++)
            M[j]=1;
    }
    for(int i = gmin+1; i <= gmax; i++)
    {
        if(M[i] == M[i - 1])
            dem++;
        else
            dem = 0;
        kq = max(kq, dem);
    }
    cout<<kq+1;
}

