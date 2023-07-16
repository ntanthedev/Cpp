#include<bits/stdc++.h>
using namespace std;
unsigned long long f[1000009], n,k, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("FMOD6.inp","r",stdin);
    freopen("FMOD6.out","w",stdout);
    cin>>n>>m;
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        f[i] = (f[i-1] + f[i-2])%m;
        if(f[i-2] == 0 && f[i-1] == 1 && f[i] == 1)
        {
            k = i-2;
            break;
        }
    }
    cout<<f[n%k];
}
