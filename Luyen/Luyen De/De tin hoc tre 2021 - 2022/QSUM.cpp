#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, Q, L, R, S;
int main()
{
    freopen("QSUM.inp","r",stdin);
    freopen("QSUM.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>Q;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    for(int i = 1; i <= Q; i++)
    {
        cin>>L>>R;
        S = 0;
        while(L<=R)
        {
            S += a[L];
            L++;
        }
        cout<<S<<'\n';
    }
}
