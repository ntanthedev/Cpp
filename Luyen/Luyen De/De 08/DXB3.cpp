#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, res = 0, gmax = 0;
map<long long, long long>M;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DXB3.inp","r",stdin);
    freopen("DXB3.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        M[a[i]]++;
        if(M[a[i]] > gmax)
        {
            res = a[i];
            gmax = M[a[i]];
        }
    }
    for(int i = 1; i <= n; i++)
        if(M[a[i]] == gmax && res > a[i])
        {
            gmax = M[a[i]];
            res = a[i];
        }
    cout<<res;
}
