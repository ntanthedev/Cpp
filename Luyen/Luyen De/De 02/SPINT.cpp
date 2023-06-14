#include<bits/stdc++.h>
using namespace std;
long long n, a[1000009], t = 1;
map<long long, long long>M;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SPINT.inp","r",stdin);
    freopen("SPINT.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        M[a[i]]++;
    }
    for(int i = 1; i <= n + 1; i++)
        if(M[i] == 0)
        {
            t = i;
            break;
        }
    cout<<t;
}
